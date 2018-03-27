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
3
5
5 4 3 2 1
2
2 4
3 4
3
2 3 1
0
4
1 2 3 4
3
1 2
3 4
2 3

output
5 3 2 4 1
2 3 1
IMPOSSIBLE

https://www.acmicpc.net/problem/3665
/* Copyright (C) 2018 by Son */

using namespace std;

vector<vector<int>> v;
int arr[501];		// �ϵ� ���� ���� ��
int ind[501];
// ��������ʿ��� ���� ������ ����
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j, s, c, n, m, a, b;
	vector<int>::iterator it;
	cin >> c;
	for (s = 0; s < c; s++) {
		cin >> n;
		string result = "";
		v = vector<vector<int>>(n+1);
		cin >> arr[0];
		ind[arr[0]] = 0;
		for (i = 1; i < n; i++) {
			cin >> arr[i];
			ind[arr[i]] = i;
			// ������� ���� ������� �� edge�� �־���
			for (j = 0; j < i; j++) {
				v[arr[j]].push_back(arr[i]);
			}
		}
		queue<int> q;
		cin >> m;
		for (i = 0; i < m; i++) {
			cin >> a >> b;
			// a�� �յ���̸� �ٲ�
			if ((it = find(v[a].begin(), v[a].end(), b)) != v[a].end()) {
				ind[b]--;
				ind[a]++;
				v[a].erase(it);
				v[b].push_back(a);
			}
			// b�� �յ�� �̸� �ٲ�
			else {
				it = find(v[b].begin(), v[b].end(), a);
				// ����� ����
				ind[a]--;
				// ����� ����
				ind[b]++;
				v[b].erase(it);
				v[a].push_back(b);
			}
		}
		for (i = 1; i <= n; i++) {
			if (!ind[i]) {
				q.push(i);
			}
		}
		bool flag = 1;
		for (i = 1; i <= n; i++) {
			// ��� ������ ����Ŭ
			if (q.empty()) {
				cout << "IMPOSSIBLE\n";
				flag = 0;
				break;
			}
			// 1�� �̻� ���� �ϸ� ����� �ָŸ�ȣ
			else if (q.size() > 1) {
				cout << "?\n";
				flag = 0;
				break;
			}
			else {
				a = q.front();
				q.pop();
				result += (to_string(a) + " ");
				for (int w : v[a]) {
					ind[w]--;
					if (!ind[w]) {
						q.push(w);
					}
				}
			}
		}
		if (flag) {
			cout << result << "\n";
		}
	}
	return 0;
}