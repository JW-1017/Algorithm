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
ACAK

https://www.acmicpc.net/problem/9252
/* Copyright (C) 2018 by Son */

using namespace std;

bool flag[1001][1001];
int dp[1001][1001];
pair<int, int> pr[1001][1001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j, maxv = 0, a = 0, b = 0;
	string s1, s2, result = ""; 
	cin >> s1 >> s2;

	int len1 = s1.length();		// 가로 문자
	int len2 = s2.length();		// 세로 문자 (열 증가하며 가로문자 하나 하나 비교)
	for (i = 1; i <= len2; i++) {
		for (j = 1; j <= len1; j++) {
			// 같으면
			if (s2[i - 1] == s1[j - 1]) {
				// 같아졌다 flag
				flag[i][j] = 1;
				// 길이 증가
				dp[i][j] = dp[i - 1][j - 1] + 1;
				// 앞에가 없으면 자기 자신 대입
				if (pr[i-1][j-1].first == 0 || pr[i-1][j-1].second == 0) {
					pr[i][j].first = i;
					pr[i][j].second = j;
				}
				else {
					// 플래그 있으면 새로 길어진 flag 부분 문자열
					if (flag[i - 1][j - 1]) {
						pr[i][j] = pair<int, int>(i - 1, j - 1);
					}
					// 없으면 대각선 부분 땡겨오기
					else {
						pr[i][j] = pr[i - 1][j - 1];
					}
				}
				// 길이 비교
				if (maxv < dp[i][j]) {
					maxv = dp[i][j];
					// 가장 끝 가장 긴 문자열의 마지막 저장
					a = i; b = j;
				}
			}
			else {
				// 다르면 긴쪽으로 
				if (dp[i - 1][j] > dp[i][j - 1]) {
					dp[i][j] = dp[i - 1][j];
					// 플래그 있으면 해당 자리
					if (flag[i - 1][j]) {
						pr[i][j] = pair<int, int>(i - 1, j);
					}
					// 없으면 긴쪽 땡겨옴
					else {
						pr[i][j] = pr[i - 1][j];
					}
				}
				else {
					dp[i][j] = dp[i][j - 1];
					// 플래그 있으면 해당 자리
					if (flag[i][j - 1]) {
						pr[i][j] = pair<int, int>(i, j - 1);
					}
					// 없으면 긴쪽 땡겨옴
					else {
						pr[i][j] = pr[i][j - 1];
					}
				}
			}
		}
	}
	result = s2[a - 1];
	while (1) {
		i = pr[a][b].first;
		j = pr[a][b].second;
		// 같으면 탈출
		if (i == a && j == b) {
			break;
		}
		result = s2[i - 1] + result;
		a = i, b = j;
	}
	cout << maxv << "\n";
	cout << result << "\n";
	return 0;
}