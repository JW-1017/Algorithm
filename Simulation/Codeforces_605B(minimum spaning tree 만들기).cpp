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
4 5
2 1
3 1
4 0
1 1
5 0

output
2 4
1 4
3 4
3 1
3 2

http://codeforces.com/problemset/problem/605/B
/* Copyright (C) 2018 by Son J.W*/

typedef long long ll;
typedef pair<int, int> pa;
typedef pair<int, pair<int, int>> ppa;

class pb {
public:
	// weight, ���Կ���, index
	int first;
	int second;
	int index;

	pb() {}
	pb(int a, int b, int index) {
		this->first = a;
		this->second = b;
		this->index = index;
	}
	// ���� ���� �� weight�� �۰�, ���Կ��δ� 1�� pair�� �տ� ����
	bool operator <(const pb& k) const{
		if (this->first < k.first) {
			return 1;
		}
		else if (this->first > k.first) {
			return 0;
		}
		else {
			if (this->second > k.second) {
				return 1;
			}
			else {
				return 0;
			}
		}
	}
};

// ��� �����
pa res[100000];
vector<pb> v;

int main() {
	bool t;
	int i, n, m, a, b = 0, c, temp = 1;
	cin >> n >> m;
	priority_queue<pb> pq;
	for (i = 0; i < m; i++) {
		cin >> a >> t;
		if (t) {
			b++;
		}
		v.push_back(pb(a, t, i));
	}
	if (b > n - 1) {
		cout << "-1\n";
		return 0;
	}
	sort(v.begin(), v.end());
	a = 1;
	b = 1;
	c = 3;
	for (i = 0; i < m; i++) {
		pb t = v[i];
		if (t.second) {
			// ���� �Ǿ� �ִٸ� 1-2 2-3 �̷������� ���� �ص�
			res[t.index] = pa(a, a + 1);
			a++;
		}
		else {
			// ���� �� �������� ����� �ִ� ������ ���� ex) a == 4�̸�
			// 1, 3, 2, 4 (1,2 2,3 �� �ȵ�)
			// �� �� �Ѿ ������ ����
			if (c > a) {
				cout << "-1\n";
				return 0;
			}
			res[t.index] = pa(b, c);
			b++;
			// ���ռ��� �տ����� �� �� ���� ������ �۰�
			// Ŀ������ c�� ������ �� ����
			if (b >= c-1) {
				b = 1;
				c++;
			}
		}
	}
	for (i = 0; i < m; i++) {
		cout << res[i].first << " " << res[i].second << "\n";
	}
	return 0;
}