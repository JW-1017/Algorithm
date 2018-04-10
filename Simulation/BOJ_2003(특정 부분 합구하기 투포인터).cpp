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
			// ������ ���� + ������ġ ���ֱ� (���ο� ������ġ���� ��)
			sum -= arr[st];
			st++;
		}
		else if (sum > m) {
			// ũ�� ������ġ ���ָ鼭 �۰ų� ������ ������ �ݺ�
			do {
				sum -= arr[st];
				st++;
			} while (sum > m);
			// ������ Ƚ������
			if (sum == m) {
				num++;
			}
		}
	}
	cout << num << "\n";
	return 0;
}