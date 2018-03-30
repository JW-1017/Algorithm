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
Find Cycle

input
7 9
1 4
4 5
5 1
1 6
6 7
2 7
7 3
3 7
7 2

output
3
1 4 5 -1
2 3 7 -1
6 -1

https://www.acmicpc.net/problem/2150
/* Copyright (C) 2018 by Son J.W*/

// SCC 코사라주 알고리즘
using namespace std;

typedef vector<int> jw;
typedef pair<int, string> pis;

int v, e, num;
bool vis[10001];
vector<jw> adj;
vector<jw> r_adj;
stack<int> rt_dfs;
set<int> s;

void dfs1(int i) {
	vis[i] = 1;
	for (int k : adj[i]) {
		if (!vis[k]) {
			dfs1(k);
		}
	}
	// 끝나는 위치부터 스택에 추가
	rt_dfs.push(i);
}
// 정방향 인접행렬에 대해 dfs결과가 stack에 쌓이고 그에 대해 dfs 
void dfs2(int i) {
	vis[i] = 1;
	for (int k : r_adj[i]) {
		if (!vis[k]) {
			dfs2(k);
		}
	}
	// 오름차순 출력을 위해 set에 추가
	s.insert(i);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, a, b;
	string str;
	vector<pis> vpis;
	cin >> v >> e;
	
	adj = vector<jw>(v + 1);
	r_adj = vector<jw>(v + 1);

	for (i = 0; i < e; i++) {
		cin >> a >> b;
		// 정방향 인접 행렬
		adj[a].push_back(b);
		// 역방향 인접 행렬
		r_adj[b].push_back(a);
	}
	// 정방향에 대하여 dfs
	for (i = 1; i <= v; i++) {
		if (!vis[i]) {
			dfs1(i);
		}
	}
	// visit 0으로 초기화
	memset(vis, 0, v + 1);
	// 스택이 빌때까지 역방향 dfs
	while (!rt_dfs.empty()) {
		// 위에서 부터
		a = rt_dfs.top();
		rt_dfs.pop();
		if (!vis[a]) {
			num++;
			dfs2(a);
			// 맨앞에 위치값으로 비교
			a = *s.begin();
			// 결과에 대한 문자열 만듬
			str = to_string(a) + " ";
			s.erase(a);
			for (int k : s) {
				str += to_string(k) + " ";
			}
			str += "-1\n";
			// 맨앞 값과 string 저장
			vpis.push_back(pis(a, str));
			s.clear();
		}
	}
	// sorting
	sort(vpis.begin(), vpis.end());
	cout << num << "\n";
	for (pis k : vpis) {
		cout << k.second;
	}
	return 0;
}