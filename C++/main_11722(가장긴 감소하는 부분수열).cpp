#include <cstdio>
#include <vector>
#include <functional>
#include <algorithm>

#pragma warning(disable:4996)
/*
input
6
10 30 10 20 20 10

output
3

https://www.acmicpc.net/problem/11722

/* Copyright (C) 2017 by Son */

using namespace std;

// upper_bound lower_bound는 정렬된 상태(기본 오름차순)에서만 사용 가능
// 인자로 greater<int>를 주면 내림차순으로 정렬된 자료에서 사용가능 하며 upper_bound가 작은 값 반환
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
		if (dp[size] > value) {
			dp.push_back(value);
			size++;
			continue;
		}
		else if (dp[size] == value) {
			continue;
		}
		if (size == 0) {
			dp[0] = value;
		}
		else {
			loc = lower_bound(dp.begin(), dp.end(), value, greater<int>());
			*loc = value;
		}
	}
	printf("%d\n", size + 1);
	
	return 0;
}