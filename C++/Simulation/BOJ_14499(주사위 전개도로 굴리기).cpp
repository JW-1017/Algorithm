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
3 3 0 0 16
0 1 2
3 4 5
6 7 8
4 4 1 1 3 3 2 2 4 4 1 1 3 3 2 2

output
0
0
0
6
0
8
0
2
0
8
0
2
0
8
0
2

https://www.acmicpc.net/problem/14499
/* Copyright (C) 2018 by Son */

using namespace std;

void jswap(int& a, int& b) {
	int temp = b;
	b = a;
	a = temp;
}
int arr[20][20];
int dice[6];	// F B Re T L Ri
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j, n, m, x, y, c, temp, sel;
	cin >> n >> m >> y >> x >> c;		// 앞에가 y좌표 입력임

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (i = 0; i < c; i++) {
		cin >> sel;
		if (sel == 3) {			// 북쪽 이동시 왼쪽 오른쪽 고정, 나머지는 한칸씩 밀림(아랫면이 뒷면으로)
			if (y - 1 < 0) {
				continue;
			}
			else {
				y--;
				temp = dice[3];
				for (j = 3; j > 0; j--) {
					dice[j] = dice[j-1];
				}
				dice[0] = temp;
			}
		}
		else if (sel == 4) {	// 남쪽 이동시 왼쪽 오른쪽 고정, 나머지는 한칸씩 땡김(아랫면이 앞면으로)
			if (y + 1 == n) {
				continue;
			}
			else {
				y++;
				temp = dice[0];
				for (j = 0; j < 3; j++) {
					dice[j] = dice[j + 1];
				}
				dice[3] = temp;
			}
		}
		else if (sel == 1) {		 // 예제 몇개 만들어 보면 동 서 는 SWAP으로 쉽게
			if (x + 1 == m) {
				continue;
			}
			else {
				x++;
				jswap(dice[1], dice[5]);
				jswap(dice[3], dice[4]);
				jswap(dice[4], dice[5]);
			}
		}
		else {
			if (x - 1 < 0) {
				continue;
			}
			else {
				x--;
				jswap(dice[1], dice[4]);
				jswap(dice[3], dice[5]);
				jswap(dice[4], dice[5]);
			}
		}
		cout << dice[3] << "\n";
		if (arr[y][x] == 0) {
			arr[y][x] = dice[1];
		}
		else {
			dice[1] = arr[y][x];
			arr[y][x] = 0;
		}
	}
	return 0;
}