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
6 8
1 2
2 5
5 1
3 4
4 6
5 4
2 4
2 3

output
1

https://www.acmicpc.net/problem/11724
/* Copyright (C) 2018 by Son */

using namespace std;

int v;
bool visited[1001];
bool arr[1001][1001];

void dfs(int ind) {
	for (int i = 1; i <= v; i++) {
		if (arr[ind][i] == 1 && !visited[i]) {
			visited[i] = 1;
			dfs(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j, e, a, b, num = 0;

	cin >> v >> e;
	for (i = 0; i < e; i++) {
		cin >> a >> b;
		// 무방향 그래프
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	for (i = 1; i <= v; i++) {
		if (!visited[i]) {
			num++;
			visited[i] = 1;
			dfs(i);
		}
	}
	cout << num << "\n";
	return 0;
}