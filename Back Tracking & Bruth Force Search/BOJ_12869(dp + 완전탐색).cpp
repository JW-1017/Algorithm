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
1.첫 번째로 공격받는 SCV는 체력 9를 잃는다.
2.두 번째로 공격받는 SCV는 체력 3을 잃는다.
3.세 번째로 공격받는 SCV는 체력 1을 잃는다.

SCV의 체력이 0 또는 그 이하가 되어버리면, SCV는 그 즉시 파괴된다. 한 번의 공격에서 같은 SCV를 여러 번 공격할 수는 없다.

남아있는 SCV의 체력이 주어졌을 때, 모든 SCV를 파괴하기 위해 공격해야 하는 횟수의 최솟값을 구하는 프로그램을 작성하시오.

input:
3
12 10 4

output:
2

https://www.acmicpc.net/problem/12869

/* Copyright (C) 2018 by Son J.W*/

int minv = 100, n;
vector<int> orig;

// a, b, c 체력 및 진행 횟수
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

	// n이 3보다 작을 때 대비
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

	// 이미 진행된거면 바로 리턴
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
	// 돌면서 체크
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