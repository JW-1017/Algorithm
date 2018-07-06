#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cctype>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <functional>
#include <algorithm>
#include <cstdlib>

using namespace std;

/*
input:
24
39
0
output:
6
3

https://www.acmicpc.net/problem/15685

/* Copyright (C) 2018 by Son J.W*/

int dir[4] = { 1, -1, -1, 1};

vector<int> _path;
bool arr[101][101];

int main(){
	int i, j, k, n, a, b, d, g, l;
	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> a >> b >> d >> g;
		arr[b][a] = 1;
		if (d % 2 != 0) {
			b += dir[d];
		}
		else {
			a += dir[d];
		}
		arr[b][a] = 1;
		_path.push_back(d);  
		for (j = 0; j < g; j++) {
			l = _path.size();
			for (k = l - 1; k >= 0; k--) {
				d = (_path[k] + 1) % 4;
				_path.push_back(d);
				if (d % 2 != 0) {
					b += dir[d];
				}
				else {
					a += dir[d];
				}
				arr[b][a] = 1;
			}
		}
		_path.clear();
	}
	l = 0;
	for (i = 0; i < 100; i++) {
		for (j = 0; j < 100; j++) {
			if (arr[i][j] && arr[i + 1][j] && arr[i][j + 1] && arr[i + 1][j + 1]) {
				l++;
			}
		}
	}
	cout << l << "\n";
	return 0;
}