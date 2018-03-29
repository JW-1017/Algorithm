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
4 6
110110
110110
111111
111101

output
9

https://www.acmicpc.net/problem/2178
/* Copyright (C) 2018 by Son */

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector<vector<int>> adj;
// 초기 좌표값
bool arr[100][100];
// 방문했는지 여부
int vis[10000];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j, n, m, t, a, b;
	queue<int> q;
	string str;
	cin >> n >> m;
	// 미리 다 넣어두고 나중에 edge 추가
	for (i = 0; i < n; i++) {
		cin >> str;
		for (j = 0; j < m; j++) {
			vector<int> k;
			adj.push_back(k);
			arr[i][j] = (bool)(str[j] - '0');
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (arr[i][j]) {
				for (t = 0; t < 4; t++) {
					a = i + dx[t], b = j + dy[t];
					if (a != -1 && b != -1 && a != n && b != m && arr[a][b]) {
						// 주변노드가 1이면 edge추가
						adj[i*m + j].push_back(a*m + b);
					}
				}
			}
		}
	}
	// BFS visited로 거리까지 해결 (큐에서 꺼낼때마다 현재 가중치 + 1)
	q.push(0);
	vis[0] = 1;
	while (!q.empty()) {
		t = q.front();
		q.pop();
		for (int w : adj[t]) {
			if (!vis[w]) {
				q.push(w);
				vis[w] = vis[t]+1;
			}
		}
	}
	cout << vis[m*n - 1] << "\n";
	return 0;
}