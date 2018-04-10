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
10
2 1
3 1
4 2
5 1
6 2
7 5
8 6
9 8
10 5
1 0 1 1 0 1 0 1 0 1
1 0 1 0 0 1 1 1 0 1

output
2
4
7

http://codeforces.com/problemset/problem/429/A
/* Copyright (C) 2018 by Son J.W*/

using namespace std;

typedef pair<int, int> pa;

vector<unordered_set<int>> adj;

int a, minv, cur, cnt;
int dep[100001];
bool vis[100001];
bool arr[2][100001];
vector<int> v;
set<pa> s;

void dfs(int i) {
	vis[i] = 1;
	// 자신 자손의 자손은 차가 2의 배수
	if ((dep[i] - cur) % 2 == 0) {
		arr[0][i] = !arr[0][i];
		if (arr[0][i] != arr[1][i]) {
			// 다르면 현재 위치를 변경 (이후 위치는 원상태 유지)
			arr[0][i] = !arr[0][i];
			cnt++;
			// 현재 위치 추가
			v.push_back(i);
			// set에서 삭제
			s.erase(pa(dep[i], i));
			return;
		}
		else {
			// 같으면 set에서 삭제
			s.erase(pa(dep[i], i));
		}
	}
	for (int k : adj[i]) {
		if (!vis[k]) {
			dfs(k);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, b, n;
	minv = (int)1e9;
	cin >> n;
	queue<int> q;
	adj = vector<unordered_set<int>>(n + 1);
	dep[1] = 1;
	for (i = 0; i < n - 1; i++) {
		cin >> a >> b;
		adj[b].insert(a);
		adj[a].insert(b);
	}
	q.push(1);
	// depth를 구함
	for (i = 1; i <= n; i++) {
		a = q.front();
		q.pop();
		for (int k : adj[a]) {
			if (!dep[k]) {
				dep[k] = dep[a] + 1;
				q.push(k);
				adj[k].erase(a);
			}
		}
	}
	for (i = 1; i <= n; i++) {
		cin >> arr[0][i];
	}
	for (i = 1; i <= n; i++) {
		cin >> arr[1][i];
		// 다를 경우 depth 작은 것을 기준으로 정렬
		if (arr[0][i] != arr[1][i]) {
			s.insert(pa(dep[i], i));
		}
	}
	if (s.empty()) {
		cout << "0\n";
		return 0;
	}
	while (1) {
		cnt++;
		pa k = (*(s.begin()));
		s.erase(k);
		a = k.second;
		cur = k.first;
		v.push_back(a);
		dfs(a);
		if (s.empty()) {
			break;
		}
		memset(vis, 0, n + 1);
	}
	cout << cnt << "\n";
	a = v.size();
	for (i = 0; i < a; i++) {
		cout << v[i] << "\n";
	}
	return 0;
}