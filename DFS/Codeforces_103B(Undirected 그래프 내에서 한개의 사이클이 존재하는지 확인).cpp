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
6 6
6 3
6 4
5 1
2 5
1 4
5 4

output
FHTAGN!

한 개의 그래프 내에 한개의 사이클이 존재하는지 확인
(두 개 이상의 그래프 x, 한개의 사이클(3개 이상의 점)만 가능)

/* Copyright (C) 2018 by Son J.W*/

using namespace std;

int v, cnt;
bool visited[101];
vector<vector<int>> adj;

void dfs(int i, int prev) {
	visited[i] = 1;
	cnt++;
	for (int k : adj[i]) {
		if (k == prev) {
			continue;
		}
		if (!visited[k]) {
			dfs(k, i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, e, a, b;
	cin >> v >> e;
	adj = vector<vector<int>>(v + 1);

	for (i = 0; i < e; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	// v가 e보다 크면 1개 사이클 이상의 edge가 존재한다는 것
	if (v != e) {
		cout << "NO\n";
		return 0;
	}
	// 아무 정점부터 dfs 시작 (해당 dfs내 간선개수를 봐서 한번에 간선개수 만큼 나오면 1개 그래프, 안 나오면 별도의 그래프 존재) 
	dfs(1, 0);
	if (e != cnt) {
		cout << "NO\n";
	}
	else {
		cout << "FHTAGN!\n";
	}
	return 0;
}