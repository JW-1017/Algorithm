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
7 7
2 0 0 0 1 1 0
0 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 0 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0

output
27

https://www.acmicpc.net/problem/14502
/* Copyright (C) 2018 by Son */

using namespace std;

/*
next_permutation을 활용하여 1을 둘 수 있는 모든 위치 탐색
1 세개 나머지 0으로 (좌표를 1자리로)
*/

int n, m, cnt;
int arr[8][8];
int temp[8][8];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void solve2(int x, int y) {
	int i, a, b;
	for (i = 0; i < 4; i++) {
		a = x + dx[i], b = y + dy[i];
		if (a != -1 && a != n && b != -1 && b != m && !temp[a][b]) {
			// 빼고 현재 위치 3으로
			cnt--;
			temp[a][b] = 3;
			solve2(a, b);
		}
	}
}
void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// 2일 때 현재 값 바꾸고 재귀 (2일때는 값 감소 하면 안됨 이미 감소시킨 채로 개수를 계산)
			if (temp[i][j] == 2) {
				temp[i][j] = 3;
				solve2(i, j);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j, num = 0, result = 0;
	vector<int> xy;
	bool* sol;
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (!arr[i][j]) {
				xy.push_back(i*m + j);		// xy 위치에 0의 위치
				num++;			// 0의 개수 (2의 개수 및 1의 개수 뺀 개수)
			}
		}
	}
	sol = new bool[num];		// 초기화 해줘야됨
 	memset(sol, 0, num);
	sol[0] = 1; sol[1] = 1; sol[2] = 1;		// sol이 1이되는 인덱스에 xy값으로 좌표 설정
	do {
		cnt = num - 3;		// 벽 3개 두니까
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				temp[i][j] = arr[i][j];		// 사용을 위해 (값이 변경됨)
			}
		}
		for (i = 0; i < num; i++) {
			if (sol[i]) {					
				temp[xy[i] / m][xy[i] % m] = 1;
			}
		}
		solve();
		result = max(result, cnt);
	} while (prev_permutation(sol, sol + num));
	cout << result << "\n";
	return 0;
}