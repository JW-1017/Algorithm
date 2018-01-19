#include <cstdio>
#include <functional>
#include <algorithm>

#pragma warning(disable:4996)
/*
input
17
7 2 1 1 5 2 2 3 2 3 1 2 4 5 1 2 4

15
1 3 2 3 2 23 3 2 23 2 30 2 3 2 23

output
6
7

https://www.acmicpc.net/problem/11054

/* Copyright (C) 2017 by Son */

using namespace std;

int main() {
	int i, num, size = 0, size2 = 0;
	int temp, result = 0;
	int* dp;
	int* dp2;
	int* dp3;
	int* loc;

	scanf("%d", &num);

	dp = new int[num];
	dp2 = new int[num];
	dp3 = new int[num];

	for (i = 0; i < num; i++) {
		scanf("%d", &dp[i]);
	}
	for (i = 0; i < num; i++) {				// 모든 index를 대상으로 바이토닉 수열을 구함(양쪽 감소확인)
		temp = i - 1;			
		size = 0, size2 = 0;
		dp2[size] = dp[i];
		dp3[size2] = dp[i];

		while (temp >= 0) {
			if (dp2[size] > dp[temp]) {
				dp2[++size] = dp[temp];
				temp--;
			}
			else if (dp2[size] == dp[temp]) {
				temp--;
			}
			else {
				if (dp[temp] >= dp[i]) {
					temp--;
					continue;
				}
				loc = lower_bound(dp2 + 1, dp2 + size + 1, dp[temp], greater<int>());
				*loc = dp[temp];
				temp--;
			}
		}
		temp = i + 1;
		while (temp < num) {
			if (dp3[size2] > dp[temp]) {
				dp3[++size2] = dp[temp];
				temp++;
			}
			else if (dp3[size2] == dp[temp]) {
				temp++;
			}
			else {
				if (dp[temp] >= dp[i]) {
					temp++;
					continue;
				}
				loc = lower_bound(dp3 + 1, dp3 + size2 + 1, dp[temp], greater<int>());
				*loc = dp[temp];
				temp++;
			}
		}
		
		result = max(result, size + size2 + 1);
	}
	delete[] dp;
	delete[] dp2;
	delete[] dp3;
	printf("%d\n", result);
	return 0;
}