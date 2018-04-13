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
#include <unordered_map>
#include <unordered_set>
/*

input
3 5 10
5 3 7

output
10

https://www.acmicpc.net/problem/1495
/* Copyright (C) 2018 by Son J.W*/

using namespace std;

unordered_set<int> s[2];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	bool t = 0;
	int i, n, p, m, temp, maxv = -1;
	cin >> n >> p >> m;
	s[0].insert(p);
	for (i = 0; i < n-1; i++) {
		cin >> temp;
		for (int k : s[t]) {
			if (temp + k <= m) {
				s[!t].insert(temp + k);
			}
			if (k - temp >= 0) {
				s[!t].insert(k - temp);
			}
		}
		s[t].clear();
		t = !t;
	}
	cin >> temp;
	for (int k : s[t]) {
		if (temp + k <= m) {
			maxv = max(temp + k, maxv);
		}
		if (k - temp >= 0) {
			maxv = max(k - temp, maxv);
		}
	}
	cout << maxv << "\n";
}