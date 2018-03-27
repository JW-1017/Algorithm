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
7
0110100
0110101
1110101
0000111
0100000
0111110
0111000

output
3
7
8
9

https://www.acmicpc.net/problem/2667
/* Copyright (C) 2018 by Son */

using namespace std;

int n, num, temp;
vector<int> v;
int arr[25][25];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void solve2(int x, int y) {
	int a, b;
	for (int i = 0; i < 4; i++) {
		a = x + dx[i]; b = y + dy[i];
		if (a != -1 && a != n && b != -1 && b != n && arr[a][b] == 1) {
			temp++;
			arr[a][b] = -1;
			solve2(a, b);
		}
	}
}
void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1) {
				num++;
				temp++;
				arr[i][j] = -1;
				solve2(i, j);
				v.push_back(temp);
				temp = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j;
	string s;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> s;
		for (j = 0; j < n; j++) {
			arr[i][j] = s[j] - '0';
		}
	}
	solve();
	cout << num << "\n";
	sort(v.begin(), v.end());
	j = v.size();
	for (i = 0; i < j; i++) {
		cout << v[i] << "\n";
	}
	return 0;
}