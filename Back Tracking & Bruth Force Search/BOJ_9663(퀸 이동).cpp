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
#include <unordered_map>
#include <unordered_set>
/*

input
8

output
92

https://www.acmicpc.net/problem/9663
/* Copyright (C) 2018 by Son J.W*/

using namespace std;

int cnt, n;
bool check[15][15];
bool col[15];

int dx[2] = { 1, 1 };
int dy[2] = { 1, -1 };

void solve(int low) {
	int i, j, a, b, temp;
	queue<int> back_t;
	for (i = 0; i < n; i++) {
		if (!col[i] && !check[low][i]) {
			if (low == (n - 1)) {
				cnt++;
			}
			else {
				col[i] = 1;
				for (j = 0; j < 2; j++) {
					a = low, b = i;
					while (1) {
						a += dx[j], b += dy[j];
						if (a != -1 && b != -1 && a != n && b != n) {
							if (!check[a][b] && !col[b]) {
								check[a][b] = 1;
								back_t.push(a*n + b);
							}
						}
						else {
							break;
						}
					}
				}
				solve(low + 1);
				col[i] = 0;
				while (!back_t.empty()) {
					temp = back_t.front();
					back_t.pop();
					check[temp / n][temp % n] = 0;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	solve(0);
	cout << cnt << "\n";
	return 0;
}