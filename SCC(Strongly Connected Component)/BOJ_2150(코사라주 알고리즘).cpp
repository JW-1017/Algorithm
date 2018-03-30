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

// SCC �ڻ���� �˰���
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
	// ������ ��ġ���� ���ÿ� �߰�
	rt_dfs.push(i);
}
// ������ ������Ŀ� ���� dfs����� stack�� ���̰� �׿� ���� dfs 
void dfs2(int i) {
	vis[i] = 1;
	for (int k : r_adj[i]) {
		if (!vis[k]) {
			dfs2(k);
		}
	}
	// �������� ����� ���� set�� �߰�
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
		// ������ ���� ���
		adj[a].push_back(b);
		// ������ ���� ���
		r_adj[b].push_back(a);
	}
	// �����⿡ ���Ͽ� dfs
	for (i = 1; i <= v; i++) {
		if (!vis[i]) {
			dfs1(i);
		}
	}
	// visit 0���� �ʱ�ȭ
	memset(vis, 0, v + 1);
	// ������ �������� ������ dfs
	while (!rt_dfs.empty()) {
		// ������ ����
		a = rt_dfs.top();
		rt_dfs.pop();
		if (!vis[a]) {
			num++;
			dfs2(a);
			// �Ǿտ� ��ġ������ ��
			a = *s.begin();
			// ����� ���� ���ڿ� ����
			str = to_string(a) + " ";
			s.erase(a);
			for (int k : s) {
				str += to_string(k) + " ";
			}
			str += "-1\n";
			// �Ǿ� ���� string ����
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