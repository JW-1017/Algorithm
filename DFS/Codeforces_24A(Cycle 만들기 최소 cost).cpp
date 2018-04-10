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
#include <bitset>
#include <unordered_set>
#include <unordered_map>
/*
input
6
1 5 4
5 3 8
2 4 15
1 6 16
2 3 23
4 6 42

output
39

http://codeforces.com/problemset/problem/24/A
/* Copyright (C) 2018 by Son J.W*/

using namespace std;

typedef pair<int, int> pa;

int v, minv;
vector<vector<int>> adj;
vector<unordered_map<int, int>> r_adj;

void dfs(int i, int cost, int prev) {
	// 정방향에 대해서
	for (int k : adj[i]) {
		// 나를 불렀던 노드면 x
		if (k == prev) {
			continue;
		}
		if (k == 1) {
			minv = min(cost, minv);
			return;
		}
		dfs(k, cost, i);
	}
	// 역방향에 대해서
	for (pa k : r_adj[i]) {
		// 나를 불렀던 노드면 x
		if (k.first == prev) {
			continue;
		}
		if (k.first == 1) {
			minv = min(cost + k.second, minv);
			return;
		}
		dfs(k.first, cost + k.second, i);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, a, b, c;
	minv = (int)1e9;
	cin >> v;
	// 정방향
	adj = vector<vector<int>>(v + 1);
	// 역방향
	r_adj = vector<unordered_map<int, int>>(v + 1);

	for (i = 0; i < v; i++) {
		cin >> a >> b >> c;
		adj[a].push_back(b);
		r_adj[b][a] = c;
	}
	// 1에서 이어지는 노드로
	for (int k : adj[1]) {
		dfs(k, 0, 1);
	}
	// 역방향 1에서 이어지는 노드로 (cost +)
	for (pa k : r_adj[1]) {
		dfs(k.first, k.second, 1);
	}
	cout << minv << "\n";
	return 0;
}