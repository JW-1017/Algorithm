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
// �ش� ������ ���� �Ǵ� ������ �ִ밪
int dp[15];

/*
���� �ҿ�Ǵ� ���� 3�� �̶�� 1 2 3������ ���Ѵ� 
���� 3�� �� 4���� ���͵� ���� ����ģ ����

���� ������ ���� n-1��
*/

int solve(int d) {
	// ���� ���� ������ �ҿ� ���� ���� �� �� ������+1 ���� ũ��
	int temp;
	int t = d + tbl[0][d];
	// ������ + 1 �� ���� Ŭ��
	if (t > n) {
		return (dp[d] = 0);
	}
	// ������ + 1 �� �� ������ (�� ������������ ������ ��)
	if (t == n) {
		return (dp[d] = tbl[1][d]);
	}
	// -1�� �ʱ�ȭ �����Ƿ� ���� �����ϸ� return
	if (dp[d] >= 0) {
		return dp[d];
	}
	// ���� �� ����
	temp = tbl[1][d];
	for (int i = t; i < n; i++) {
		// ���鼭 ���ϴ� ��
		temp += solve(i);
		// ���� ��ġ������ �ִ밪�� ����
		dp[d] = max(dp[d], temp);
		// �ٽ� �ʱ�ȭ
		temp = tbl[1][d];
	}
	// ������ġ������ �ִ밪�� ��ȯ
	return dp[d];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i;
	cin >> n;
	memset(dp, -1, 4 * n);
	// n-1�� ���� ���� �� n ��
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