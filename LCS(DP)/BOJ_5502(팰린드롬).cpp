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
#include <sstream>

using namespace std;

/*
팰린드롬이란 대칭 문자열이다
최소 개수의 문자를 삽입하여 팰린드롬이 되게 되는 문자의 개수를 구하는 프로그램

input:
5
Ab3bd

output:
2

https://www.acmicpc.net/problem/5502
/* Copyright (C) 2018 by Son J.W*/

typedef pair<int, int> pa;
typedef vector<int> vi;
typedef vector<vi> vvi;

int arr[5001][5001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int i, j, len, maxv = 0;
	string str, r_str;
	cin >> len;
	cin >> str;

	r_str = str;

	reverse(r_str.begin(), r_str.end());

	if (str == r_str) {
		cout << 0 << "\n";
		return 0;
	}
	// lcs (역순 문자열과 최대 공통부분 문자열 찾음)
	for (i = 1; i <= len; i++) {
		for (j = 1; j <= len; j++) {
			if (str[i-1] == r_str[j-1]) {
				arr[i][j] = arr[i - 1][j - 1] + 1;
				maxv = max(arr[i][j], maxv);
			}
			else {
				arr[i][j] = max(arr[i][j - 1], arr[i - 1][j]);
			}
		}
	}
	// 길이 - lcs결과 가 결국 삽입하는 문자 수
	cout << len - maxv << "\n";
	return 0;
}