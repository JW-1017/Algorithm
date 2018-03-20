#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <map>
#include <set>
#include <list>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <numeric>
#include <cmath>
#include <unordered_set>
#include <unordered_map>

#pragma warning(disable:4996)

/*
input
6 5
1 1 1 0 0
1 1 1 0 0
1 1 1 0 1
1 1 0 1 1
0 1 1 0 0
0 0 0 0 0

output
2
13

https://www.acmicpc.net/problem/1926
/* Copyright (C) 2018 by Son */

using namespace std;

int num, sum, n, m, max_sum;		// n �� m ��
set<pair<int, int>> s;
bool arr[500][500];

void back_t(int l, int c) {
	if (!arr[l][c]) {
		return;
	}
	// ���� ��ġ�� 0����
	arr[l][c] = 0;
	// 1�� ���� ����
	sum++;
	// set���� ���� (�ۿ� set���� �ſ��� ���̱� ����)
	s.erase(pair<int, int>(l, c));
	// �Ʒ� ���� �� �� Ȯ��
	if (l + 1 != n) {
		back_t(l + 1, c);
	}
	if (c + 1 != m) {
		back_t(l, c + 1);
	}
	if (l - 1 != -1) {
		back_t(l - 1, c);
	}
	if (c - 1 != -1) {
		back_t(l, c - 1);
	}
}
void solve() {
	// 1�� ��ġ�� ���� set�� ���鼭 ( set���� �ݺ��� ���� ��ü!!element�� ��������)
	for (pair<int, int> t : s) {
		max_sum = max(sum, max_sum);
		// ���ۺ��� ũ�� 1
		sum = 1;
		// ���� ����, back_t ���ο����� ���� x
		num++;
		// ������ġ 0���� (���ٰ� ���Եɼ� ����)
		arr[t.first][t.second] = 0;
		// �Ʒ�
		if (t.first + 1 != n) {
			back_t(t.first + 1, t.second);
		}
		// ����
		if (t.second + 1 != m) {
			back_t(t.first, t.second + 1);
		}
		// ��
		if (t.first - 1 != -1) {
			back_t(t.first - 1, t.second);
		}
		// ����
		if (t.second - 1 != -1) {
			back_t(t.first, t.second - 1);
		}
	}
	max_sum = max(sum, max_sum);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j]) {
				s.insert(pair<int, int>(i, j));
			}
		}
	}
	solve();
	cout << num << "\n" << max_sum << "\n";
	return 0;
}