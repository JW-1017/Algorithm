#include <cstdio>
#include <algorithm>

#pragma warning(disable:4996)
/*
input
6
10
20
15
25
10
20

output
75

https://www.acmicpc.net/problem/2579

/* Copyright (C) 2017 by Son */

using namespace std;

int main() {
	int i, num;
	int* arr;
	int score[10000][2];		// 0은 2칸전 1은 1칸전
	
	scanf("%d", &num);
	arr = new int[num];

	for (i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}
	score[0][0] = arr[0];
	score[0][1] = arr[0];
	score[1][0] = arr[1];
	score[1][1] = arr[0] + arr[1];

	// 현재 요소에서 밟을때 최대값
	for (i = 2; i < num; i++) {
		score[i][0] = max(score[i - 2][0], score[i - 2][1]) + arr[i];
		score[i][1] = score[i - 1][0] + arr[i];
	}
	
	//마지막은 무조건 밟아야 하므로 현재의 최대
	printf("%d\n", max(score[num - 1][0], score[num - 1][1]));

	delete[] arr;
	return 0;
}