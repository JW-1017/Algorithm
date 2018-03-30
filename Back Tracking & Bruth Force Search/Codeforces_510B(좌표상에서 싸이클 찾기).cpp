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
Find Cycle

input
4 4
YYYR
BYBY
BBBY
BBBY

output
Yes

http://codeforces.com/contest/510/problem/B
/* Copyright (C) 2018 by Son J.W*/

using namespace std;

// 나중에 SCC 공부하고 다시 풀기

int n, m;
// 4방향 저장
int dir[4];
int arr[50][50];
// 바로 이전 좌표로 안돌아가기 위해 (x좌표 +1 일땐 x좌표 -1일 경우 무시)
int loc[5] = { 1, 0, 3, 2, -1 };
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
// 지나간 점을 저장하는 set
unordered_set<int> s;

int solve2(int x, int y, int t, int k) {
	// 현재 위치 추가
	s.insert(x*m + y);
	// -값으로 변경
	arr[x][y] = -t;
	bool flag;
	int i, a, b;
	for (i = 0; i < 4; i++) {
		// 바로 이전점이면 넘어감
		if (loc[k] == i) {
			continue;
		}
		// 이미 해당 위치 dir값이 1으로 세팅 되어있는지 확인하는 flag
		flag = 1;
		a = x + dx[i];
		b = y + dy[i];
		if (a != -1 && b != -1 && a != n && b != m) {
			// -값 일 때
			if (arr[a][b] == -t) {
				// 이미 setting 되어있으면 flag 0으로 (백트래킹을 위해)
				if (dir[i] == 1) {
					flag = 0;
				}
				dir[i] = 1;
				if (dir[0] && dir[1] && dir[2] && dir[3]) {
					// 4방향 모두 지났을 때
					return 1;
				}
				// 세팅되어 있지 않은 상태일때 0 으로 다시
				if (flag) {
					dir[i] = 0;
				}
			}
			else if (arr[a][b] == t) {
				// 똑같이 방향값 확인
				if (dir[i] == 1) {
					flag = 0;
				}
				dir[i] = 1;
				if (solve2(a, b, t, i)) {
					return 1;
				}
				// 값 되돌리고 방향값 되돌리기 (백트래킹)
				arr[a][b] = t;
				if (flag) {
					dir[i] = 0;
				}
			}
		}
	}
	return 0;
}
void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s.find(i*m+j) == s.end()) {
				// 시작 k 위치는 무의미한값으로
				if (solve2(i, j, arr[i][j], 4)) {
					cout << "Yes\n";
					return;
				}
				memset(dir, 0, sizeof(dir));
			}
		}
	}
	cout << "No\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j;
	string s;
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		cin >> s;
		for (j = 0; j < m; j++) {
			arr[i][j] = s[j] - 'A' + 1;
		}
	}
	solve();
	
	return 0;
}