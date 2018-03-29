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
120

output
252

https://www.acmicpc.net/problem/1748
/* Copyright (C) 2018 by Son */

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, s, k;
	// 1�ڸ� �϶� �� 9�ڸ�
	long long len = 9;
	string str;
	cin >> str;
	k = stoi(str);
	// ���� ����
	n = str.length();
	if (n == 1) {
		cout << k * 1 << "\n";
		return 0;
	}
	// ���� �ڸ����� ���� ������ s
	s = (int)pow(10, n - 1);
	while (1) {
		if (n == 1) {
			break;
		}
		// ���� �� - s + 1 �� ��ŭ�� n�ڸ���
		len += (k - s + 1)*n;
		// s-1�� �� �� �ڸ��� �ִ밪 ����
		k = s - 1;
		// s /= 10���� �� �� �ڸ��� �ּҰ� ����
		s /= 10;
		n--;
	}
	cout << len << "\n";
	return 0;
}