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
60
100

output
245
64

https://www.acmicpc.net/problem/1977
/* Copyright (C) 2018 by Son J.W*/

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	bool flag = 0;
	int i, a, b, t, sum = 0, minv;
	cin >> a >> b;
	for (i = a; i <= b; i++) {
		t = (int)sqrt(i);
		if (t*t == i) {
			sum += i;
			if (!flag) {
				minv = i;
				flag = 1;
			}
		}
	}
	if (!flag) {
		cout << "-1\n";
	}
	else {
		cout << sum << "\n" << minv << "\n";
	}
	return 0;
}