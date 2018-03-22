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
11
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 14

output
4

https://www.acmicpc.net/problem/1931
/* Copyright (C) 2018 by Son */

using namespace std;

// 끝시간이 짧은거 기준 정렬
class jw {
public:
	int a, b;
	jw(int a, int b):a(a), b(b){}
	bool operator<(const jw& t) const {
		if (this->b < t.b) {
			return 1;
		}
		else if (this->b == t.b) {
			return this->a < t.a;
		}
		else {
			return 0;
		}
	}
};

vector<jw> v;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, n, a, b;
	priority_queue<int> pq;

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back(jw(a, b));
	}
	// 정렬
	sort(v.begin(), v.end());
	// 끝시간이 큰게 top으로 오게(top보다 크거나 같아야 추가 가능)
	pq.push(v[0].b);
	for (i = 1; i < n; i++) {
		a = pq.top();
		if (v[i].a >= a) {
			pq.push(v[i].b);
		}
	}
	cout << pq.size() << "\n";
	return 0;
}