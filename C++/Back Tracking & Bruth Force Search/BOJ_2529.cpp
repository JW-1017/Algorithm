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
2
< >

output
897
021

https://www.acmicpc.net/problem/2529
/* Copyright (C) 2018 by Son */

using namespace std;

int n;
bool arr[10];
int result[10];
string t = "";

bool solve1(int ind) {
	if (ind == n+1) {
		return 1;
	}
	for (int i = 0; i < 10; i++) {
		if (arr[i]) {
			continue;
		}
		if (t[ind-1] == '>') {
			if (result[ind - 1] < i) {
				continue;
			}
		}
		else {
			if (result[ind - 1] > i) {
				continue;
			}
		}
		result[ind] = i;
		arr[i] = 1;
		if (solve1(ind + 1)) {
			return 1;
		}
		arr[i] = 0;
	}
	return 0;
}
bool solve2(int ind) {
	if (ind == n + 1) {
		return 1;
	}
	for (int i = 9; i > -1; i--) {
		if (arr[i]) {
			continue;
		}
		if (t[ind - 1] == '>') {
			if (result[ind - 1] < i) {
				continue;
			}
		}
		else {
			if (result[ind - 1] > i) {
				continue;
			}
		}
		result[ind] = i;
		arr[i] = 1;
		if (solve2(ind + 1)) {
			return 1;
		}
		arr[i] = 0;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i;
	char s;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> s;
		t += s;
	}
	for (i = 9; i >= 0; i--) {
		arr[i] = 1;
		result[0] = i;
		if (solve2(1)) {
			break;
		}
		arr[i] = 0;
	}
	for (i = 0; i < n + 1; i++) {
		cout << result[i];
	}
	cout << "\n";
	memset(arr, 0, n + 1);
	for (i = 0; i < 10; i++) {
		arr[i] = 1;
		result[0] = i;
		if (solve1(1)) {
			break;
		}
		arr[i] = 0;
	}
	for (i = 0; i < n + 1; i++) {
		cout << result[i];
	}
	cout << "\n";
	return 0;
}