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
3
26 40 83
49 60 57
13 89 99

output
96

https://www.acmicpc.net/problem/1149
/* Copyright (C) 2018 by Son */

using namespace std;

int n;
int arr[3][1000];
int memo[3][1000];

// �ش� ��ġ ������ ���� �ּҸ� �����ذ� (�ش� ������ �����ٸ� ���� ����ǵ� ���� �ּҸ� ���� ��)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, a, b, c;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a >> b >> c;
		arr[0][i] = a;
		arr[1][i] = b;
		arr[2][i] = c;
	}
	memo[0][0] = arr[0][0];
	memo[1][0] = arr[1][0];
	memo[2][0] = arr[2][0];
	for (i = 1; i < n; i++) {
		// x�� ������ ���� ������ �ּҰ��� ������ x�̿��� ���� ���°����� �ּ� + ���� x��
		memo[0][i] = min(memo[1][i - 1] + arr[0][i], memo[2][i - 1] + arr[0][i]);
		memo[1][i] = min(memo[0][i - 1] + arr[1][i], memo[2][i - 1] + arr[1][i]);
		memo[2][i] = min(memo[0][i - 1] + arr[2][i], memo[1][i - 1] + arr[2][i]);
	}
	cout << min(memo[0][n - 1], min(memo[1][n - 1], memo[2][n - 1])) << "\n";
	return 0;
}