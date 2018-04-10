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
#include <bitset>
#include <unordered_set>
#include <unordered_map>

#pragma warning(disable:4996)

/*
input
10 5
1 2 3 4 2 5 3 1 1 2

output
3

https://www.acmicpc.net/problem/2003
/* Copyright (C) 2018 by Son J.W*/

using namespace std;

int arr[10000];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j, n, m, num = 0, sum = 0, st;
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	st = 0;
	for (i = 0; i < n; i++) {
		sum += arr[i];
		if (sum == m) {
			num++;
			// 같으면 증가 + 시작위치 빼주기 (새로운 시작위치부터 합)
			sum -= arr[st];
			st++;
		}
		else if (sum > m) {
			// 크면 시작위치 빼주면서 작거나 같아질 때까지 반복
			do {
				sum -= arr[st];
				st++;
			} while (sum > m);
			// 같으면 횟수증가
			if (sum == m) {
				num++;
			}
		}
	}
	cout << num << "\n";
	return 0;
}