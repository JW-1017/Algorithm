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
ACAYKP
CAPCAK

output
4

https://www.acmicpc.net/problem/9251
/* Copyright (C) 2018 by Son */

using namespace std;

// 길이에 대한 표
/*
ex) 연속적이지 않은 최장 공통 부분 문자열
  0 A C A Y K P
0 
C 0 0 1 1 1 1 1
A 0 1 1 2 2 2 2
P 0 1 1 2 2 2 3
C 0 1 2 2 2 2 3
A 0 1 2 3 3 3 3
K 0 1 2 3 3 4 4
*/
int arr[1001][1001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j, len1, len2, max_n = 0;
	string str1, str2;
	cin >> str1 >> str2;
	len1 = str1.length();
	len2 = str2.length();
	for (i = 1; i <= len1; i++) {
		for (j = 1; j <= len2; j++) {
			// 문자열이 같다면 대각선 위쪽 + 1
			if (str1[i - 1] == str2[j - 1]) {
				arr[i][j] = arr[i - 1][j - 1] + 1;
			}
			// 다르면 왼쪽 위쪽 중 최대값
			else {
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
			}
			max_n = max(arr[i][j], max_n);
		}
	}
	cout << max_n << "\n";
	return 0;
}