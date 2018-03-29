#include <cstdio>
#include <algorithm>

#pragma warning(disable:4996)
/*
input
6
6
10
13
9
8
1

output
33

https://www.acmicpc.net/problem/2156
/* Copyright (C) 2017 by Son */

using namespace std;

int main() {
	int i, num;
	int* arr;
	int score[10000][3];		// 0은 3칸전 1은 2칸전 2은 1칸전

	scanf("%d", &num);
	arr = new int[num];

	for (i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}
	if (num == 1) {
		printf("%d\n", arr[0]);
		delete[] arr;
		return 0;
	}
	score[0][0] = arr[0];
	score[0][1] = arr[0];
	score[0][2] = arr[0];
	score[1][0] = arr[1];
	score[1][1] = arr[1];
	score[1][2] = arr[0] + arr[1];
	score[2][0] = arr[2];
	score[2][1] = arr[0] + arr[2];
	score[2][2] = arr[1] + arr[2];

	for (i = 3; i < num; i++) {
		score[i][0] = max(max(score[i - 3][0], score[i - 3][1]), score[i - 3][2]) + arr[i];
		score[i][1] = max(max(score[i - 2][0], score[i - 2][1]), score[i - 2][2]) + arr[i];
		score[i][2] = max(score[i - 1][0], score[i - 1][1]) + arr[i];
	}
	// 끝점으로부터 2칸앞 혹은 1칸앞부터 연속과 이전요소의 연속 둘중 최대값이 최대값
	printf("%d\n", max(max(score[num - 1][1], score[num - 1][2]), score[num - 2][2]));

	delete[] arr;
	return 0;
}