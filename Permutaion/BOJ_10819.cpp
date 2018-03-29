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
6
20 1 15 8 4 10

output
62

https://www.acmicpc.net/problem/10819
/* Copyright (C) 2018 by Son */

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j, n, k = 0, temp, max_val = (int)-1e9;
	int* arr1;
	int* arr2;
	cin >> n;
	arr1 = new int[n];
	arr2 = new int[n];
	for (i = 0; i < n; i++) {
		cin >> arr1[i];
		arr2[i] = arr1[i];
	}
	do {
		temp = 0;
		for (i = 1; i < n; i++) {
			temp += abs(arr1[i] - arr1[i - 1]);
		}
		max_val = max(temp, max_val);
	} while (next_permutation(arr1, arr1 + n));

	while (prev_permutation(arr2, arr2 + n)) {
		temp = 0;
		for (i = 1; i < n; i++) {
			temp += abs(arr2[i] - arr2[i - 1]);
		}
		max_val = max(temp, max_val);
	}
	cout << max_val << "\n";
	delete[] arr1;
	delete[] arr2;
	return 0;
}