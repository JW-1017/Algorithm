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
4
1 5 4 7

output
6

http://codeforces.com/problemset/problem/788/A
/* Copyright (C) 2018 by Son J.W*/

typedef long long ll;
typedef pair<int, int> pa;
typedef pair<int, pair<int, int>> ppa;

int arr[100000];

int main() {
	int i, n;
	long long maxv = (long long)-1e17;
	long long tempsum = 0;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (i = 0; i < n-1; i++) {
		if (i % 2 == 0) {
			tempsum += abs(arr[i] - arr[i + 1]);
			maxv = max(maxv, tempsum);
		}
		else {
			tempsum += (abs(arr[i] - arr[i + 1]) * -1);
			if (tempsum < 0) {
				tempsum = 0;
			}
		}
	}
	tempsum = 0;
	for (i = 1; i < n - 1; i++) {
		if (i % 2 == 0) {
			tempsum += (abs(arr[i] - arr[i + 1]) * -1);
			if (tempsum < 0) {
				tempsum = 0;
			}
		}
		else {
			tempsum += abs(arr[i] - arr[i + 1]);
			maxv = max(maxv, tempsum);
		}
	}
	cout << maxv << "\n";
	return 0;
}