#include <cstdio>
#include <vector>
#include <algorithm>

#pragma warning(disable:4996)

/*
input
6
10 20 10 30 20 50

output
4

https://www.acmicpc.net/problem/12738

/* Copyright (C) 2017 by Son */

using namespace std;

int main() {
	int i, num, size = 0;
	int value;
	vector<int> dp;
	vector<int>::iterator loc;
	scanf("%d", &num);

	scanf("%d", &value);
	dp.push_back(value);

	for (i = 1; i < num; i++) {
		scanf("%d", &value);
		if (dp[size] < value) {
			dp.push_back(value);
			size++;
			continue;
		}
		else if (dp[size] == value) {
			continue;
		}
		loc = lower_bound(dp.begin(), dp.end(), value);
		*loc = value;
	}
	printf("%d\n", size + 1);
	return 0;
}