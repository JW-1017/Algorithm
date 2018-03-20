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

output
220

https://www.acmicpc.net/problem/11057
/* Copyright (C) 2018 by Son */

#define mod 10007

/*
�ᱹ � ���ں��ʹ� �޺κ� ����� ���� ������
[0~9����][��ġ]
�� ����� ���� ����
*/

using namespace std;

int n;
long long cnt;

int arr[10][1001];

int solve(int k, int l) {
	// �޺κ��� �����̴� (memo)
	if (arr[k][l]) {
		return arr[k][l];
	}
	if (l == n) {
		return 1;
	}
	// �ڱ� �̻��� ���ؼ� ����
	for (int i = k; i < 10; i++) {
		arr[k][l] = (arr[k][l] + solve(i, l + 1)) % mod;
	}
	return arr[k][l];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i;
	cin >> n;
	if (n == 1) {
		cout << "10\n";
		return 0;
	}
	for (i = 0; i <= 9; i++) {
		cnt = (cnt + solve(i, 1)) % mod;
	}
	cout << cnt << "\n";
	return 0;
}