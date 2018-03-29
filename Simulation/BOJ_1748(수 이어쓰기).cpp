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
	// 1자리 일때 총 9자리
	long long len = 9;
	string str;
	cin >> str;
	k = stoi(str);
	// 수의 길이
	n = str.length();
	if (n == 1) {
		cout << k * 1 << "\n";
		return 0;
	}
	// 현재 자리수중 가장 작은수 s
	s = (int)pow(10, n - 1);
	while (1) {
		if (n == 1) {
			break;
		}
		// 현재 수 - s + 1 개 만큼의 n자리수
		len += (k - s + 1)*n;
		// s-1로 그 전 자리수 최대값 생성
		k = s - 1;
		// s /= 10으로 그 전 자리수 최소값 생성
		s /= 10;
		n--;
	}
	cout << len << "\n";
	return 0;
}