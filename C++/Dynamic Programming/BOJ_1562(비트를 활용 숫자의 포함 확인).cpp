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

/*
input 
10

output
1

https://www.acmicpc.net/problem/1562
/* Copyright (C) 2018 by Son J.W*/

#define mod 1000000000
#define full 1023

using namespace std;

int n;
long long r;
// 해당 숫자, 해당 위치, 비트(0 ~ 9까지 써졌는지)
int dp[10][101][1024];

int solve(int d, int l, int s) {
	// d값이 범위를 넘으면 바로 리턴
	if (d == -1 || d == 10) {
		return 0;
	}
	// reference로 해당 값 저장
	s |= (1 << d);
	int& res = dp[d][l][s];

	if (l == n) {
		if (s == full) {
			return 1;
		}
		return 0;
	}
	if (res != -1) {
		return res;
	}

	return (res = (solve(d + 1, l + 1, s) + solve(d - 1, l + 1, s)) % mod);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i;
	cin >> n;

	// 안쓴 것에 대해 -1로 초기화
	memset(dp, -1, sizeof(dp));
	for (i = 1; i < 10; i++) {
		r = (r + solve(i, 1, 0)) % mod;
	}
	cout << r << "\n";
	return 0;
}