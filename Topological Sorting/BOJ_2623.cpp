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
6 3
3 1 4 3
4 6 2 5 4
2 2 3

output
6
2
1
5
4
3

https://www.acmicpc.net/problem/2623
/* Copyright (C) 2018 by Son J.W*/

using namespace std;

int ind[1001];
vector<vector<int>> adj;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	string result = "";
	int i, j, k, n, m, a, temp, prev;
	cin >> n >> m;
	queue<int> q;
	adj = vector<vector<int>>(n + 1);
	
	for (i = 0; i < m; i++) {
		cin >> a;
		cin >> prev;
		for (j = 1; j < a; j++) {
			cin >> temp;
			adj[prev].push_back(temp);
			ind[temp]++;
			prev = temp;
		}
	}
	for (i = 1; i <= n; i++) {
		if (!ind[i]) {
			q.push(i);
		}
	}
	for (i = 1; i <= n; i++) {
		if (q.empty()) {
			cout << "0\n";
			return 0;
		}
		temp = q.front();
		q.pop();
		result += to_string(temp) + "\n";
		for (int s : adj[temp]) {
			ind[s]--;
			if (!ind[s]) {
				q.push(s);
			}
		}
	}
	cout << result;
	return 0;
}