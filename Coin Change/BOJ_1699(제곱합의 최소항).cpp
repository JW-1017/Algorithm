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
7

output
4

https://www.acmicpc.net/problem/1699
/* Copyright (C) 2018 by Son J.W*/

using namespace std;

int dp[100001];
int arr[351];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j, n, r = 0;
	cin >> n;
	memset(dp, (int)1e6, 4 * (n + 1));

	// 합하는 수를 돌게 해서 중복을 없앰
	for (j = 1; j <= 350; j++) {
		if (!arr[j]) {
			arr[j] = j*j;
		}
		if (arr[j] > n) {
			break;
		}
		for (i = 1; i <= n; i++) {
			if (i < arr[j]) {
				continue;
			}
			else if (i == arr[j]) {
				dp[i] = 1;
				continue;
			}
			else {
				// 현재 값을 뺀 위치 만큼 연산횟수 +1 
				dp[i] = min(dp[i], dp[i - arr[j]] + 1);
			}
		}
	}
	cout << dp[n] << "\n";
	return 0;
}