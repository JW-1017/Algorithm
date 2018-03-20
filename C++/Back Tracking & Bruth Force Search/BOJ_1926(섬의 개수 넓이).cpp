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

int num, sum, n, m, max_sum;		// n 행 m 열
set<pair<int, int>> s;
bool arr[500][500];

void back_t(int l, int c) {
	if (!arr[l][c]) {
		return;
	}
	// 현재 위치를 0으로
	arr[l][c] = 0;
	// 1의 개수 증가
	sum++;
	// set에서 없앰 (밖에 set도는 거에서 줄이기 위해)
	s.erase(pair<int, int>(l, c));
	// 아래 오른 위 좌 확인
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
	// 1인 위치를 담은 set을 돌면서 ( set에서 반복문 도중 객체!!element만 삭제가능)
	for (pair<int, int> t : s) {
		max_sum = max(sum, max_sum);
		// 시작부터 크기 1
		sum = 1;
		// 갯수 증가, back_t 내부에서는 증가 x
		num++;
		// 현재위치 0으로 (돌다가 포함될수 있음)
		arr[t.first][t.second] = 0;
		// 아래
		if (t.first + 1 != n) {
			back_t(t.first + 1, t.second);
		}
		// 우측
		if (t.second + 1 != m) {
			back_t(t.first, t.second + 1);
		}
		// 위
		if (t.first - 1 != -1) {
			back_t(t.first - 1, t.second);
		}
		// 좌측
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