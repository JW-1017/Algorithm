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
1 2 3 4 5 6
2 1 1 1

output
54
-24

https://www.acmicpc.net/problem/14888
/* Copyright (C) 2018 by Son */

using namespace std;

int arr[11];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j, n, k = 0, temp, max_val = (int)-1e9, min_val = (int)1e9;
	int* cal;
	cin >> n;
	cal = new int[n - 1];
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (i = 0; i < 4; i++) {
		cin >> temp;
		for (j = 0; j < temp; j++) {
			cal[k] = i;
			k++;
		}
	}
	do {
		temp = arr[0];
		k = 0;
		for (i = 1; i < n; i++,k++) {
			if (cal[k] == 0) {
				temp += arr[i];
			}
			else if (cal[k] == 1) {
				temp -= arr[i];
			}
			else if (cal[k] == 2) {
				temp *= arr[i];
			}
			else {
				temp /= arr[i];
			}
		}
		max_val = max(max_val, temp);
		min_val = min(min_val, temp);
	} while (next_permutation(cal, cal + n - 1));
	cout << max_val << "\n" << min_val << "\n";
	return 0;
}