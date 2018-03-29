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
2
10 8 17
0 0
1 0
1 1
4 2
4 3
4 5
2 4
3 4
7 4
8 4
9 4
7 5
8 5
9 5
7 6
8 6
9 6
10 10 1
5 5

output
5
1

https://www.acmicpc.net/problem/1012
/* Copyright (C) 2018 by Son */

using namespace std;

int n, m, num;
vector<vector<bool>> v;

void solve2(int a, int b) {
	if (v[a][b] == 0) {
		return;
	}
	v[a][b] = 0;
	if (a + 1 != n) {
		solve2(a + 1, b);
	}
	if (b + 1 != m) {
		solve2(a, b+1);
	}
	if (a - 1 != -1) {
		solve2(a - 1, b);
	}
	if (b - 1 != -1) {
		solve2(a, b-1);
	}
}
void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j]) {
				num++;
				solve2(i, j);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j, tc, cnt, x, y;
	cin >> tc;
	for (i = 0; i < tc; i++) {
		num = 0;
		cin >> m >> n >> cnt;
		v.assign(n, vector<bool>(m,0));
		for (j = 0; j < cnt; j++) {
			cin >> x >> y;
			v[y][x] = 1;
		}
		solve();
		cout << num << "\n";
	}
	return 0;
}