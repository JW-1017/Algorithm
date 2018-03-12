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
1 3
2 4
3 5

output
2

https://www.acmicpc.net/problem/11000
/* Copyright (C) 2018 by Son */

using namespace std;

class jw2 {
public:
	int a;
	int b;
	jw2() {}
	jw2(int a, int b) {
		this->a = a;
		this->b = b;
	}
	bool operator <(const jw2& t) const{
		if (this->a == t.a) {
			return this->b < t.b;
		}
		else {
			return this->a < t.a;
		}
	}
	bool operator >(const jw2& t) const {
		if (this->a == t.a) {
			return this->b > t.b;
		}
		else {
			return this->a > t.a;
		}
	}
	bool operator ==(const jw2& t) const {
		if (this->a == t.a) {
			return this->b == t.b;
		}
		return 0;
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, n, a, b, temp;
	priority_queue<int, vector<int>, greater<int>> pq;
	vector<jw2> v;
	
	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back(jw2(a, b));
	}
	sort(v.begin(), v.end());
	pq.push(v[0].b);
	
	for (i = 1; i < n; i++) {
		temp = pq.top();
		if (temp > v[i].a) {
			pq.push(v[i].b);
		}
		else {
			pq.pop();
			pq.push(v[i].b);
		}
	}
	cout << pq.size() << "\n";
	return 0;
}