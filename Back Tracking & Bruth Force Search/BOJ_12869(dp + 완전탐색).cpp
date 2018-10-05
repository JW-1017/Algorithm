#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cctype>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <functional>
#include <algorithm>
#include <cstdlib>

using namespace std;

/*
1.ù ��°�� ���ݹ޴� SCV�� ü�� 9�� �Ҵ´�.
2.�� ��°�� ���ݹ޴� SCV�� ü�� 3�� �Ҵ´�.
3.�� ��°�� ���ݹ޴� SCV�� ü�� 1�� �Ҵ´�.

SCV�� ü���� 0 �Ǵ� �� ���ϰ� �Ǿ������, SCV�� �� ��� �ı��ȴ�. �� ���� ���ݿ��� ���� SCV�� ���� �� ������ ���� ����.

�����ִ� SCV�� ü���� �־����� ��, ��� SCV�� �ı��ϱ� ���� �����ؾ� �ϴ� Ƚ���� �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

input:
3
12 10 4

output:
2

https://www.acmicpc.net/problem/12869

/* Copyright (C) 2018 by Son J.W*/

int minv = 100, n;
vector<int> orig;

// a, b, c ü�� �� ���� Ƚ��
bool dp[61][61][61][21];

bool isZero(vector<int> v, int len) {
	for (int i = 0; i < len; i++) {
		if (v[i] > 0) {
			return false;
		}
	}
	return true;
}

void mutal(vector<int> v, int cnt) {
	if (cnt >= minv) {
		return;
	}
	int v1, v2;

	// n�� 3���� ���� �� ���
	if (n == 1) {
		v1 = v2 = 0;
	}
	else if (n == 2) {
		v1 = v[1];
		v2 = 0;
	}
	else {
		v1 = v[1];
		v2 = v[2];
	}

	// �̹� ����ȰŸ� �ٷ� ����
	if (dp[v[0]][v1][v2][cnt] == 1) {
		return;
	}
	dp[v[0]][v1][v2][cnt] = 1;
	if (isZero(v, n)) {
		minv = min(minv, cnt);
		return;
	}
	int i, temp = 9;
	cnt++;

	for (i = 0; i < n; i++) {
		v[i] -= temp;
		if (v[i] < 0) {
			v[i] = 0;
		}
		temp /= 3;
	}
	sort(v.begin(), v.end(), greater<int>());
	// ���鼭 üũ
	do {
		vector<int> vv;
		for (i = 0; i < n; i++) {
			vv.push_back(v[i]);
		}
		mutal(vv, cnt);
	} while (prev_permutation(v.begin(), v.end()));
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, cnt = 0;

	cin >> n;
	orig = vector<int>(n);
	for (i = 0; i < n; i++) {
		cin >> orig[i];
	}
	sort(orig.begin(), orig.end(), greater<int>());
	do {
		vector<int> v;
		for (i = 0; i < n; i++) {
			v.push_back(orig[i]);
		}
		mutal(v, 0);
	} while (prev_permutation(orig.begin(), orig.end()));

	cout << minv << "\n";
	return 0;
}