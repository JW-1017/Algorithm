#include <cstdlib>
#include <cstring>
#include <cctype>
#include <map>
#include <set>
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
#include <unordered_map>

using namespace std;

/*
input:
5 6
1
5 1 1
1 2 2
1 3 3
2 3 4
2 4 5
3 4 6

output:
0
2
3
7
INF

https://www.acmicpc.net/problem/1753
/* Copyright (C) 2017 by Son */

typedef pair<int, int> pa;

vector<vector<pa>> adj;
int dist[20001];
//int route[1001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, v, st, e, a, b, c, cost, cnt = 0;
	priority_queue<pa, vector<pa>, greater<pa>> pq;

	cin >> v >> e;
	adj = vector<vector<pa>>(v + 1);
	// 갱신 되지 않은 점에 대해 -1로 초기화
	memset(dist, -1, 4 * (v + 1));
	cin >> st;
	for (i = 0; i < e; i++) {
		cin >> a >> b >> c;
		adj[a].push_back(pa(b, c));
	}
	// second : index first : cost
	pq.push(pa(0, st));

	while (!pq.empty()) {
		pa t = pq.top();
		i = t.second;
		c = t.first;
		pq.pop();
		if (dist[i] != -1) {
			// 확정된 거리의 점이라면 넘어감
			continue;
		}
		// 현재 거리에 대한 확정
		dist[i] = c;
		for (auto& k : adj[i]) {
			// first : index second : cost
			if (dist[k.first] != -1) {
				continue;
			}
			cost = c + k.second;
			pq.push(pa(cost, k.first));
		}
	}
	for (i = 1; i <= v; i++) {
		if (dist[i] == -1) {
			cout << "INF\n";
			continue;
		}
		cout << dist[i] << "\n";
	}
	return 0;
}