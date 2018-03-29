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
6
1 2
2 3
1 5
5 2
5 6
4 7

output
4

https://www.acmicpc.net/problem/2606
/* Copyright (C) 2018 by Son */

using namespace std;

int n;
long long cnt;

bool visited[101];
vector<vector<int>> v;

void dfs(int idx) {
	cnt++;
	visited[idx] = 1;
	for (int t : v[idx]) {
		if (!visited[t]) {
			dfs(t);
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cnt = -1;
	int i, num, a, b;
	cin >> n >> num;
	// 열이 시작노드 열행에서의 값이 도착노드 
	for (i = 0; i <= n; i++) {
		vector<int> k;
		v.push_back(k);
	}
	for (i = 0; i < num; i++) {
		cin >> a >> b;
		// 무방향이므로
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	cout << cnt << "\n";
	return 0;
}