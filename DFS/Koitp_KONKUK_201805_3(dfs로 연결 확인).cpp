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
N개의 컴퓨터가 왼쪽에서 오른쪽으로 한 줄로 세워져 있다. 인접한 컴퓨터 간의 거리는 1이라고 하자. 
각 컴퓨터는 0 혹은 1로 번호가 붙어 있다. 이 컴퓨터들을 네트워크로 연결하려고 한다. 연결하는 방법은 다음과 같다.

번호가 1인 컴퓨터는 자신의 왼쪽에 있는 번호가 0인 컴퓨터들 중 가장 가까운 5개와 직접 연결된다. 
자신의 왼쪽에 번호가 0인 컴퓨터가 5개 미만이 존재하는 경우에는 존재하는 컴퓨터들과만 연결하면 된다.

이런 식으로 네트워크를 연결할 때 필요한 케이블의 길이를 구하고, 또, 서로 직접 혹은 간접으로 연결된 컴퓨터들의 무리가 몇 개가 있는지를 계산하는 프로그램을 작성하라. 
두 컴퓨터를 연결하는 케이블의 길이는 두 컴퓨터 간의 거리와 같다고 생각한다.

input:
16
0 0 0 0 1 0 0 1 1 1 0 0 0 0 0 1

output:
94 2

https://koitp.org/problem/KONKUK_201805_3/read/
/* Copyright (C) 2018 by Son J.W*/

bool arr[200000];
vector<int> v;
vector<vector<int>> adj;
bool visit[200000];

void dfs(int i) {
	visit[i] = 1;
	for (auto& k : adj[i]) {
		if (!visit[k]) {
			dfs(k);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int i, j, n, num = 0, t = 0, len;
	long long sum = 0;
	cin >> n;
	adj = vector<vector<int>>(n);
	cin >> arr[0];
	if (!arr[0]) {
		v.push_back(0);
	}
	for (i = 1; i < n; i++) {
		cin >> arr[i];
		t = 0;
		if (!arr[i]) {
			v.push_back(i);
		}
		else {
			len = v.size();
			for (j = len - 1; j >= 0; j--) {
				t++;
				if (t > 5) {
					break;
				}
				adj[i].push_back(v[j]);
				adj[v[j]].push_back(i);
				sum += (i - v[j]);
			}
		}
	}
	cout << sum << " ";
	
	for (i = 0; i < n; i++) {
		if (!visit[i]) {
			num++;
			dfs(i);
		}
	}
	cout << num << "\n";
	return 0;
}