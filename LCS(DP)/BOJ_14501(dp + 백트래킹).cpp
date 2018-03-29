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
10
5 10
5 9
5 8
5 7
5 6
5 10
5 9
5 8
5 7
5 6

output
20

https://www.acmicpc.net/problem/14501
/* Copyright (C) 2018 by Son J.W*/

using namespace std;

int n, mav;
int tbl[2][15];
// 해당 날부터 시작 되는 일정의 최대값
int dp[15];

/*
일이 소요되는 날이 3일 이라면 1 2 3까지만 일한다 
따라서 3일 뒤 4일이 나와도 일은 끝마친 상태

현재 마지막 날은 n-1날
*/

int solve(int d) {
	// 현재 들어온 날에서 소요 날이 지난 뒤 가 최종날+1 보다 크면
	int temp;
	int t = d + tbl[0][d];
	// 최종일 + 1 일 보다 클때
	if (t > n) {
		return (dp[d] = 0);
	}
	// 최종일 + 1 일 과 같을때 (딱 마지막날까지 일했을 때)
	if (t == n) {
		return (dp[d] = tbl[1][d]);
	}
	// -1로 초기화 했으므로 값이 존재하면 return
	if (dp[d] >= 0) {
		return dp[d];
	}
	// 현재 값 저장
	temp = tbl[1][d];
	for (int i = t; i < n; i++) {
		// 돌면서 변하는 값
		temp += solve(i);
		// 현재 위치부터의 최대값을 갱신
		dp[d] = max(dp[d], temp);
		// 다시 초기화
		temp = tbl[1][d];
	}
	// 현재위치부터의 최대값을 반환
	return dp[d];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i;
	cin >> n;
	memset(dp, -1, 4 * n);
	// n-1일 까지 존재 총 n 일
	for (i = 0; i < n; i++) {
		cin >> tbl[0][i] >> tbl[1][i];
	}
	for (i = 0; i < n; i++) {
		solve(i);
		mav = max(mav, dp[i]);
	}
	cout << mav << "\n";
	return 0;
}