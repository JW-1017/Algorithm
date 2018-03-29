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
7
0 0 0 1 0 0 0
0 0 0 0 0 0 1
0 0 0 0 0 0 0
0 0 0 0 1 1 0
1 0 0 0 0 0 0
0 0 0 0 0 0 1
0 0 1 0 0 0 0

output
1 0 1 1 1 1 1
0 0 1 0 0 0 1
0 0 0 0 0 0 0
1 0 1 1 1 1 1
1 0 1 1 1 1 1
0 0 1 0 0 0 1
0 0 1 0 0 0 0

https://www.acmicpc.net/problem/11403
/* Copyright (C) 2018 by Son */

#define NN -1999999999
// ��� ���� ���� ū or ���� ��(���Ѵ�)���� ����

using namespace std;

long long adj[100][100];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j, k, n;
	cin >> n;
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> adj[i][j];
			// ��� �������� ���� �� 0 ��(��ΰ� ���°� �ƴϴϱ�)
			if (i != j && !adj[i][j]) {
				adj[i][j] = NN;
			}
		}
	}
	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (adj[i][k] != NN && adj[k][j] != NN) {
					adj[i][j] = max(adj[i][j], adj[i][k] + adj[k][j]);
				}
			}
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (adj[i][j] > 0) {
				cout << "1 ";
			}
			else {
				cout << "0 ";
			}
		}
		cout << "\n";
	}
	return 0;
}