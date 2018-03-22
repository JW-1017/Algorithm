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
2931

output
-1

https://www.acmicpc.net/problem/10610
/* Copyright (C) 2018 by Son */

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	bool flag = 0;
	string r = "";
	int i, k = 0;
	priority_queue<char> pq;
	string s;
	cin >> s;
	int len = s.length();
	// 0을 포함하고 합이 3의 배수면 30의 배수
	for (i = 0; i < len; i++) {
		if (s[i] == '0') {
			flag = 1;
			pq.push(s[i]);
			continue;
		}
		pq.push(s[i]);
		k += s[i] - '0';
	}
	// pq에서 큰값부터 합침
	if (k % 3 == 0 && flag) {
		while (!pq.empty()) {
			r += pq.top();
			pq.pop();
		}
		cout << r << "\n";
	}
	else {
		cout << "-1\n";
	}
	return 0;
}