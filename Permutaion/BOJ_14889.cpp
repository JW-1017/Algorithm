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
6
0 1 2 3 4 5
1 0 2 3 4 5
1 2 0 3 4 5
1 2 3 0 4 5
1 2 3 4 0 5
1 2 3 4 5 0

output
2

https://www.acmicpc.net/problem/14889
/* Copyright (C) 2018 by Son J.W*/

using namespace std;

vector<bool> v;
vector<vector<int>> team;
int arr[20][20];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j, n, h, miv = 10000, a, b;
	cin >> n;
	h = n / 2;
	v = vector<bool>(n, 0);
	team = vector<vector<int>>(2);
	for (i = 0; i < h; i++) {
		v[i] = 1;
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	do {
		a = b = 0;
		// v배열로 조합
		for (i = 0; i < n; i++) {
			// team 배열에 각 팀(0, 1) 인덱스 들어감
			team[v[i]].push_back(i);
		}
		for (i = 0; i < h; i++) {
			for (j = (i+1); j < h; j++) {
				a += arr[team[0][i]][team[0][j]] + arr[team[0][j]][team[0][i]];
				b += arr[team[1][i]][team[1][j]] + arr[team[1][j]][team[1][i]];
			}
		}
		miv = min(miv, abs(a-b));
		team[0].clear();
		team[1].clear();
	} while (prev_permutation(v.begin(), v.end()));
	cout << miv << "\n";
	return 0;
}