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
	int score[10000][2];		// 0�� 2ĭ�� 1�� 1ĭ��
	
	scanf("%d", &num);
	arr = new int[num];

	for (i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}
	score[0][0] = arr[0];
	score[0][1] = arr[0];
	score[1][0] = arr[1];
	score[1][1] = arr[0] + arr[1];

	// ���� ��ҿ��� ������ �ִ밪
	for (i = 2; i < num; i++) {
		score[i][0] = max(score[i - 2][0], score[i - 2][1]) + arr[i];
		score[i][1] = score[i - 1][0] + arr[i];
	}
	
	//�������� ������ ��ƾ� �ϹǷ� ������ �ִ�
	printf("%d\n", max(score[num - 1][0], score[num - 1][1]));

	delete[] arr;
	return 0;
}