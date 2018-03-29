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

/*
input 
7
8
5 1 2
5 2 2
7 5 2
6 5 2
6 3 3
6 4 4
7 6 3
7 4 5

output
1 16
2 16
3 9
4 17

https://www.acmicpc.net/problem/2637
/* Copyright (C) 2018 by Son J.W*/

using namespace std;

typedef pair<int, int> jw;

vector<vector<jw>> adj;
int ind[101];
// 해당 행 : 당 열 : 인덱스의 부품수
int cost[101][101];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);		
	int i, j, n, m, s, t, w;
	cin >> n;
	adj = vector<vector<jw>>(n + 1);
	queue<int> q;
	cin >> m;
	for (i = 0; i < m; i++) {
		cin >> s >> t >> w;
		ind[s]++;
		adj[t].push_back(jw(s, w));
	}
	for (i = 1; i <= n; i++) {
		if (!ind[i]) {
			q.push(i);
			// 시작 값은 해당 부품만 1
			cost[i][i] = 1;
		}
	}
	for (i = 1; i <= n; i++) {
		w = q.front();
		q.pop();
		for (auto& k : adj[w]) {
			ind[k.first]--;
			for (j = 1; j <= n; j++) {
				// 돌면서 개수만큼 곱하고 더함
				cost[k.first][j] += (cost[w][j] * k.second);
			}
			if (!ind[k.first]) {
				q.push(k.first);
			}
		}
	}
	for (i = 1; i <= n; i++) {
		if (cost[n][i]) {
			cout << i << " " << cost[n][i] << "\n";
		}
	}
	return 0;
}