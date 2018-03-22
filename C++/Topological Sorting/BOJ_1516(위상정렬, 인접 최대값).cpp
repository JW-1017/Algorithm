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
5
10 -1
10 1 -1
4 1 -1
4 3 1 -1
3 3 -1

output
10
20
14
18
17

https://www.acmicpc.net/problem/1516
/* Copyright (C) 2018 by Son */

using namespace std;

int ind[501];
// �ʱ� �ð� ����
int time[501];
// �ִ� �ð� ����(�ڽ��� ��)
int m_time[501];
vector<vector<int>> adj;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int result = 0;
	queue<int> q;
	int i, n, a;
	cin >> n;
	// adj ��� �ʱ�ȭ
	for (i = 0; i <= n; i++) {
		vector<int> t;
		adj.push_back(t);
	}
	for (i = 1; i <= n; i++) {
		cin >> a;
		time[i] = a;
		while (1) {
			cin >> a;
			if (a == -1) {
				break;
			}
			ind[i]++;
			adj[a].push_back(i);
		}
	}
	for (i = 1; i <= n; i++) {
		if (!ind[i]) {
			q.push(i);
		}
	}
	for (i = 1; i <= n; i++) {
		a = q.front();
		q.pop();
		// ���� ����� �ְ� ���� �� �ڽ� �� ����
		m_time[a] += time[a];
		for (int k : adj[a]) {
			ind[k]--;
			// ����� �ֵ� �߿� �ִ밪���� ����
			m_time[k] = max(m_time[k], m_time[a]);
			if (!ind[k]) {
				q.push(k);
			}
		}
	}
	for (i = 1; i <= n; i++) {
		cout << m_time[i] << "\n";
	}
	return 0;
}