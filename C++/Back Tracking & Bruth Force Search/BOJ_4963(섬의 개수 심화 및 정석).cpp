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
1 1
0
2 2
0 1
1 0
3 2
1 1 1
1 1 1
5 4
1 0 1 0 0
1 0 0 0 0
1 0 1 0 1
1 0 0 1 0
5 4
1 1 1 0 1
1 0 1 0 1
1 0 1 0 1
1 0 1 1 1
5 5
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0

output
0
1
1
3
1
9

https://www.acmicpc.net/problem/4963
/* Copyright (C) 2018 by Son */

using namespace std;

int n, m, num;   // n이 열 m 이 행
bool arr[50][50];

void back_t(int l, int c) {
	if (!arr[l][c]) {
		return;
	}
	arr[l][c] = 0;
	if (l + 1 != m) {
		// 위쪽 대각선
		if (c + 1 != n) {
			back_t(l + 1, c + 1);
		}
		if (c - 1 != -1) {
			back_t(l + 1, c - 1);
		}
		back_t(l + 1, c);
	}
	if (l - 1 != -1) {
		// 아래쪽 대각선
		if (c + 1 != n) {
			back_t(l - 1, c + 1);
		}
		if (c - 1 != -1) {
			back_t(l - 1, c - 1);
		}
		back_t(l - 1, c);
	}
	if (c + 1 != n) {
		back_t(l, c + 1);
	}
	if (c - 1 != -1) {
		back_t(l, c - 1);
	}
}
void solve() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j]) {
				num++;
				back_t(i, j);
			}
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	while (1) {
		cin >> n >> m;
		if (n == 0) {
			return 0;
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		num = 0;
		solve();
		cout << num << "\n";
	}
	return 0;
}