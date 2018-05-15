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
N���� ��ǻ�Ͱ� ���ʿ��� ���������� �� �ٷ� ������ �ִ�. ������ ��ǻ�� ���� �Ÿ��� 1�̶�� ����. 
�� ��ǻ�ʹ� 0 Ȥ�� 1�� ��ȣ�� �پ� �ִ�. �� ��ǻ�͵��� ��Ʈ��ũ�� �����Ϸ��� �Ѵ�. �����ϴ� ����� ������ ����.

��ȣ�� 1�� ��ǻ�ʹ� �ڽ��� ���ʿ� �ִ� ��ȣ�� 0�� ��ǻ�͵� �� ���� ����� 5���� ���� ����ȴ�. 
�ڽ��� ���ʿ� ��ȣ�� 0�� ��ǻ�Ͱ� 5�� �̸��� �����ϴ� ��쿡�� �����ϴ� ��ǻ�͵���� �����ϸ� �ȴ�.

�̷� ������ ��Ʈ��ũ�� ������ �� �ʿ��� ���̺��� ���̸� ���ϰ�, ��, ���� ���� Ȥ�� �������� ����� ��ǻ�͵��� ������ �� ���� �ִ����� ����ϴ� ���α׷��� �ۼ��϶�. 
�� ��ǻ�͸� �����ϴ� ���̺��� ���̴� �� ��ǻ�� ���� �Ÿ��� ���ٰ� �����Ѵ�.

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