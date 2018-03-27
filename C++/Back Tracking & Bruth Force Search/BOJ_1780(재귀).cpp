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
9
0 0 0 1 1 1 -1 -1 -1
0 0 0 1 1 1 -1 -1 -1
0 0 0 1 1 1 -1 -1 -1
1 1 1 0 0 0 0 0 0
1 1 1 0 0 0 0 0 0
1 1 1 0 0 0 0 0 0
0 1 -1 0 1 -1 0 1 -1
0 -1 1 0 1 -1 0 1 -1
0 1 -1 1 0 -1 0 1 -1

output
10
12
11

https://www.acmicpc.net/problem/1780
/* Copyright (C) 2018 by Son J.W*/

using namespace std;

int n, cnt;
int arr[3];
vector<vector<int>> v;

void solve(int x, int y, int g) {
	int i, j, flag, m;
	flag = v[x][y];
	for (j = 1; j < g; j++) {
		if (flag == -10) {
			continue;
		}
		if (flag != v[x][y+j]) {
			flag = -10;
		}
	}
	for (i = 1; i < g; i++) {
		for (j = 0; j < g; j++) {
			if (flag == -10) {
				continue;
			}
			if (flag != v[x+i][y+j]) {
				flag = -10;
			}
		}
	}
	if (flag != -10) {
		arr[flag + 1] += 1;
		return;
	}
	m = g / 3;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			solve(x + m*i, y + m*j, m);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j, flag, m;
	cin >> n;
	m = n / 3;
	v = vector<vector<int>>(n, vector<int>(n));
	cin >> v[0][0];
	flag = v[0][0];
	for (j = 1; j < n; j++) {
		cin >> v[0][j];
		if (flag == -10) {
			continue;
		}
		if (flag != v[0][j]) {
			flag = -10;
		}
	}
	for (i = 1; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> v[i][j];
			if (flag == -10) {
				continue;
			}
			if (flag != v[i][j]) {
				flag = -10;
			}
		}
	}
	if (flag != -10) {
		arr[flag + 1] = n*n;
		for (i = 0; i < 3; i++) {
			cout << arr[i] << "\n";
		}
		return 0;
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			solve(0 + m*i, 0 + m*j, m);
		}
	}
	for (i = 0; i < 3; i++) {
		cout << arr[i] << "\n";
	}
	return 0;
}