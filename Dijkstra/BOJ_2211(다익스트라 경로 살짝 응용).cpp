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
최소인 점을 확정해 가며 나아감
확정 할 때 이전 정점을 저장

input
4 5
1 2 1
1 4 4
1 3 2
4 2 2
4 3 3

output
3
1 2
3 1
4 2

https://www.acmicpc.net/problem/1806https://www.acmicpc.net/problem/2211
/* Copyright (C) 2018 by Son J.W*/

using namespace std;

typedef pair<int, int> pa;
// first cost, second 1 index, second 2 post index
typedef pair<int, pair<int, int>> ppa;

vector<vector<pa>> adj;
int dist[1001];
int route[1001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, v, e, a, b, c, cost, cnt = 0;
	ppa t;  string res = "";
	priority_queue<ppa, vector<ppa>, greater<ppa>> pq;

	cin >> v >> e;
	adj = vector<vector<pa>>(v + 1);

	memset(dist, -1, 4 * (v + 1));
	// first index, second cost 
	for (i = 0; i < e; i++) {
		cin >> a >> b >> c;
		adj[a].push_back(pa(b, c));
		adj[b].push_back(pa(a, c));
	}
	// second : index first : cost
	pq.push(ppa(0, pa(1, 0)));

	while (!pq.empty()) {
		t = pq.top();
		// index
		i = t.second.first;
		// cost
		c = t.first;
		// save min cost
		pq.pop();
		if (dist[i] != -1) {
			continue;
		}
		dist[i] = c;
		route[i] = t.second.second;
		for (auto& k : adj[i]) {
			if (dist[k.first] != -1) {
				continue;
			}
			cost = c + k.second;
			pq.push(ppa(cost, pa(k.first, i)));
		}
	}
	for (i = 1; i <= v; i++) {
		if (route[i]) {
			if (i == route[route[i]]) {
				route[route[i]] = 0;
			}
			cnt++;
			res += to_string(i) + " " + to_string(route[i]) + "\n";
		}
	}
	cout << cnt << "\n";
	cout << res;
	return 0;
}