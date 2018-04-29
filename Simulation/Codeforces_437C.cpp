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
#include <deque>
#include <stack>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>

using namespace std;
/*
input
7 10
40 10 20 10 20 80 40
1 5
4 7
4 5
5 2
5 7
6 4
1 6
1 3
4 3
1 4

output
160

http://codeforces.com/problemset/problem/437/C
/* Copyright (C) 2018 by Son J.W*/

typedef long long ll;
typedef pair<int, int> pa;
typedef pair<int, pair<int, int>> ppa;

int arr[1001];
priority_queue<pa> pq;		// w, index
vector<unordered_map<int, int>> adj;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, n, v, a, b, sum = 0;
	cin >> n >> v;
	adj.push_back(unordered_map<int, int>());
	for (i = 1; i <= n; i++) {
		cin >> arr[i];
		// ���� �Ҹ� ū parts���� ������ ����
		pq.push(pa(arr[i], i));
		adj.push_back(unordered_map<int, int>());
	}
	for (i = 1; i <= v; i++) {
		cin >> a >> b;
		// �����
		adj[a][b] = arr[b];
		adj[b][a] = arr[a];
	}
	while (!pq.empty()) {
		pa t = pq.top();
		pq.pop();
		a = t.second;
		for (pa k : adj[a]) {
			// �ֺ� weight ���ϰ�
			sum += k.second;
			// �ڽſ��� �̾��� �� ����
			adj[k.first].erase(a);
		}
	}
	cout << sum << "\n";
	return 0;
}