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
6
12 4 11 10 7 1

output
11

https://www.acmicpc.net/problem/1017
/* Copyright (C) 2018 by Son J.W*/

typedef long long ll;
typedef pair<int, int> pa;
typedef pair<int, pair<int, int>> ppa;

int n, m, t, maxv, num, start, temp;
int arr[50];
bool visited[2001];
int e_group[25];
int bmat[1001];
vector<vector<int>> adj;
unordered_set<int> pn;

int dfs(int i) {
	if (visited[i]) {
		return 0;
	}
	visited[i] = 1;
	for (int k : adj[i]) {
		// bmat[k]�� �������̸� �ȵ�
		if (!bmat[k] || ((bmat[k] != arr[start]) && dfs(bmat[k]))) {
			bmat[k] = i;
			return 1;
		}
	}
	return 0;
}

void bmatch() {
	for (int k : adj[start]) {
		num = 1;
		memset(bmat, 0, (maxv + 1) * 4);
		bmat[k] = start;
		for (int i = 0; i < t; i++) {
			// �̺� ��Ī ����
			memset(visited, 0, maxv + 1);
			visited[start] = 1;
			if (dfs(e_group[i])) {
				// ������ n�� ���� ��ŭ
				num++;
				if (num == m) {
					break;
				}
			}
		}
		if (num == m) {
			cout << k << " ";
			temp++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int s;
	int i, j;
	cin >> n;
	// 0���� ���� �׷��� ���� ¦�� �׷� or Ȧ�� �׷����� (¦¦ �̳� ȦȦ �� ������ 2�� ����̱� ����)
	cin >> arr[0];
	s = arr[0] % 2;
	for (i = 1; i < n; i++) {
		cin >> arr[i];
		if (arr[i] % 2 == s) {
			e_group[t] = arr[i];
			t++;
		}
	}
	m = (n / 2);
	// �׷��� n�� �ݸ�ŭ �ȵǸ� ���� ��Ī�� �ȵ�
	if ((t+1) != m) {
		cout << "-1\n";
		return 0;
	}
	start = arr[0];
	// �������� ����
	sort(arr, arr + n);
	// ���� ū���� ���� �Ҽ����� �����
	maxv = arr[n - 1];
	adj = vector<vector<int>>(maxv + 1);
	maxv += maxv;
	for (i = 2; i < maxv; i++) {
		if (!visited[i]) {
			pn.insert(i);
			for (j = i; j < maxv; j += i) {
				visited[j] = 1;
			}
		}
	}
	maxv /= 2;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (pn.find(arr[i] + arr[j]) != pn.end()) {
				adj[arr[i]].push_back(arr[j]);
				adj[arr[j]].push_back(arr[i]);
			}
		}
	}
	bmatch();
	if (temp == 0) {
		cout << "-1\n";
	}
	return 0;
}