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
#include <sstream>

using namespace std;

/*
input:
2
8
3 2 7 8 1 4 5 6
10
2 1 3 4 5 6 7 9 10 8

output:
3
7

https://www.acmicpc.net/problem/10451
/* Copyright (C) 2018 by Son J.W*/

typedef pair<int, int> pa;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi adj;
vvi r_adj;
stack<int> st;
bool vis[1001];

void dfs1(int i) {
	vis[i] = 1;
	for (auto& k : adj[i]) {
		if (vis[k] == 0) {
			dfs1(k);
		}
	}
	st.push(i);
}
void dfs2(int i) {
	vis[i] = 1;
	for (auto& k : r_adj[i]) {
		if (vis[k] == 0) {
			dfs2(k);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j, test, n, temp, num;
	cin >> test;
	for (i = 0; i < test; i++) {
		cin >> n;
		num = 0;
		adj = vvi(n + 1);
		r_adj = vvi(n + 1);
		for (j = 1; j <= n; j++) {
			cin >> temp;
			adj[j].push_back(temp);
			r_adj[temp].push_back(j);
		}
		for (j = 1; j <= n; j++) {
			if (vis[j] == 0) {
				dfs1(j);
			}
		}

		memset(vis, 0, n + 1);

		while (!st.empty()) {
			temp = st.top();
			st.pop();
			if (vis[temp] == 0) {
				// 역방향 dfs가 가능할 때마다 사이클 개수 증가
				num++;
				dfs2(temp);
			}
		}
		memset(vis, 0, n + 1);
		cout << num << "\n";
	}
	return 0;
}