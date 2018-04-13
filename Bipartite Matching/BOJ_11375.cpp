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
#include <unordered_map>
#include <unordered_set>
/*
input
5 5
2 1 2
1 1
2 2 3
3 3 4 5
1 1

output
4

https://www.acmicpc.net/problem/11375
/* Copyright (C) 2018 by Son J.W*/

using namespace std;

int n, cnt;
bool vis[1001];
int bmacth[1001];
vector<vector<int>> adj;

int dfs(int i) {
	if (vis[i]) {
		return 0;
	}
	vis[i] = 1;
	for (int k : adj[i]) {
		// �湮���� �ʾҰų� ��ǥ ������ ����� �������� ���� �� �� �ٸ� ������ ���� �� �� ���� ��
		if (!bmacth[k] || dfs(bmacth[k])) {
			bmacth[k] = i;
			return 1;
		}
	}
	return 0;
}
void bmat() {
	int i;
	for (i = 1; i <= n; i++) {
		// �湮 ���θ� ��� ������ ���� ���� �ʱ�ȭ
		memset(vis + 1, 0, n);
		if (dfs(i)) {
			cnt++;
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j,  m, num, b;
	cin >> n >> m;

	vis[0] = 1;
	adj = vector<vector<int>>(n + 1);

	for (i = 1; i <= n; i++) {
		cin >> num;
		for (j = 0; j < num; j++) {
			cin >> b;
			adj[i].push_back(b);
		}
	}
	bmat();
	cout << cnt << "\n";
	return 0;
}