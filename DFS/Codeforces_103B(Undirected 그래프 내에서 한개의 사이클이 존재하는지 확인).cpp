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

�� ���� �׷��� ���� �Ѱ��� ����Ŭ�� �����ϴ��� Ȯ��
(�� �� �̻��� �׷��� x, �Ѱ��� ����Ŭ(3�� �̻��� ��)�� ����)

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
	// v�� e���� ũ�� 1�� ����Ŭ �̻��� edge�� �����Ѵٴ� ��
	if (v != e) {
		cout << "NO\n";
		return 0;
	}
	// �ƹ� �������� dfs ���� (�ش� dfs�� ���������� ���� �ѹ��� �������� ��ŭ ������ 1�� �׷���, �� ������ ������ �׷��� ����) 
	dfs(1, 0);
	if (e != cnt) {
		cout << "NO\n";
	}
	else {
		cout << "FHTAGN!\n";
	}
	return 0;
}