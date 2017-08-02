#include <cstdio>
#include <cstring>
#include <vector>

#pragma warning(disable:4996)
/*
input
6
10 20 10 30 20 50

output
4
10 20 30 50

https://www.acmicpc.net/problem/14002

/* Copyright (C) 2017 by Son */

using namespace std;

class s_node {
public:
	int num;
	s_node* prev;

	s_node() {}
	s_node(int num) {
		this->num = num;
		this->prev = NULL;
	}
	s_node(int num1, s_node* prev) {
		this->num = num1;
		this->prev = prev;
	}
};

int main() {
	int i , j, num, value;
	int result = 0, index = 0;
	vector<int> result_dp;
	s_node* temp;
	s_node* arr;
	int* dp;
	scanf("%d", &num);
	
	arr = new s_node[num];
	dp = new int[num];

	memset(dp, 0, 4 * num);
	scanf("%d", &value);
	arr[0] = s_node(value);
	dp[0]++;

	for (i = 1; i < num; i++) {
		dp[i]++;
		scanf("%d", &value);
		arr[i] = s_node(value);

		for (j = 0; j < i; j++) {
			if (arr[i].num > arr[j].num && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				arr[i].prev = &arr[j];
			}
		}
		if (result < dp[i]) {
			result = dp[i];
			index = i;
		}
	}
	printf("%d\n", result);
	temp = &arr[index];
	while (temp != NULL) {
		result_dp.push_back(temp->num);
		temp = temp->prev;
	}
	int size = result_dp.size();
	for (i = size - 1; i > 0; i--) {
		printf("%d ", result_dp[i]);
	}
	printf("%d\n", result_dp[0]);
	delete[] arr;
	delete[] dp;
	return 0;
}