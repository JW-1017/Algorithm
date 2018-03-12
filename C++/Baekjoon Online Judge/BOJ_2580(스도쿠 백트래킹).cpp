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
0 3 5 4 6 9 2 7 8
7 8 2 1 0 5 6 0 9
0 6 0 2 7 8 1 3 5
3 2 1 0 4 6 8 9 7
8 0 4 9 1 3 5 0 6
5 9 6 8 2 0 4 1 3
9 1 7 6 5 2 0 8 0
6 0 3 7 0 1 9 5 2
2 5 8 3 9 4 7 6 0

output
1 3 5 4 6 9 2 7 8
7 8 2 1 3 5 6 4 9
4 6 9 2 7 8 1 3 5
3 2 1 5 4 6 8 9 7
8 7 4 9 1 3 5 2 6
5 9 6 8 2 7 4 1 3
9 1 7 6 5 2 3 8 4
6 4 3 7 8 1 9 5 2
2 5 8 3 9 4 7 6 1

https://www.acmicpc.net/problem/2580
/* Copyright (C) 2018 by Son */

using namespace std;

bool low[9][10];
bool col[9][10];
bool squ[9][10];
int sdo[9][9];

bool sdoku() {
	int i, j, x = -1, y = -1, temp;

	// 앞에서 부터 차근차근 0인 부분 확인
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			if (sdo[i][j] == 0) {
				x = i; y = j;
				break;
			}
		}
		if (x != -1) {
			break;
		}
	}
	// 0이 아예없음을 확인
	if (x == -1) {
		// 종료 시점
		return 1;
	}
	// 인접 9개 영역(사전에 나눠진)에서 해당 영역 확인
	temp = x / 3 * 3 + y / 3;
	for (i = 1; i <= 9; i++) {
		if (!(low[x][i] || col[y][i] || squ[temp][i])) {
			sdo[x][y] = i;
			low[x][i] = col[y][i] = squ[temp][i] = 1;
			// 1이면 종료조건 (값을 되돌리는 과정 x)
			if (sdoku()) {
				return 1;
			}
			// 값을 되돌림
			sdo[x][y] = 0;
			low[x][i] = col[y][i] = squ[temp][i] = 0;
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j, temp;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			cin >> temp;
			sdo[i][j] = temp;
			low[i][temp] = 1;
			col[j][temp] = 1;
			squ[i / 3 * 3 + j / 3][temp] = 1;
		}
	}
	sdoku();
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			cout << sdo[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}