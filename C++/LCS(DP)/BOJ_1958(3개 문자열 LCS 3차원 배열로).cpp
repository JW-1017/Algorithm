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

#include <locale>

/*
input 
abcdefghijklmn
bdefg
efg

output
3

https://www.acmicpc.net/problem/1958
/* Copyright (C) 2018 by Son J.W*/

using namespace std;

int dp[101][101][101];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	string s1, s2, s3;		// s1 가로 s2 세로 s3 z축
	int i, j, k, l1, l2, l3, mav = 0;
	cin >> s1 >> s2 >> s3;
	l1 = s1.length();
	l2 = s2.length();
	l3 = s3.length();

	for (i = 1; i <= l3; i++) {
		for (j = 1; j <= l2; j++) {
			for (k = 1; k <= l1; k++) {
				if ((s3[i - 1] == s2[j - 1]) && (s2[j - 1] == s1[k - 1])) {
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
					mav = max(dp[i][j][k], mav);
				}
				else {
					dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
				}
			}
		}
	}
	cout << mav << "\n";
	return 0;
}