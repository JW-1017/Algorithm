#include <cstdio>

#define SIZE 10000
#pragma warning(disable:4996)
/*
input
10
5
2
3
1
4
2
3
5
1
7

output
1
1
2
2
3
3
4
5
5
7
https://www.acmicpc.net/problem/10989

/* Copyright (C) 2017 by Son */

int arr[SIZE+1];		// 전역변수여서 자동으로 0초기화

int main() {
	int i, j;
	int num, value;

	scanf("%d", &num);

	for (i = 0; i < num; i++) {
		scanf("%d", &value);
		arr[value]++;
	}
	for (i = 1; i < SIZE+1; i++) {			// 자연수 오름차순
		if (arr[i]) {
			for (j = 0; j < arr[i]; j++) {
				printf("%d\n", i);
			}
		}
	}
	return 0;
}