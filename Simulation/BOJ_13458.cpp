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
5
1000000 1000000 1000000 1000000 1000000
5 7

output
714290

https://www.acmicpc.net/problem/13458
/* Copyright (C) 2018 by Son J.W*/

using namespace std;

int arr[1000000];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, n, b, c;
	long long result;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> b >> c;
	result = n;
	for (i = 0; i < n; i++) {
		arr[i] -= b;
		if (arr[i] > 0) {
			result += (arr[i] / c);
			if (arr[i] % c > 0) {
				result++;
			}
		}
	}
	cout << result << "\n";
	return 0;
}