#include <cstdio>
#include <cmath>

#pragma warning(disable:4996)

/*
input
16 8 9

output
4

https://www.acmicpc.net/problem/1057

/* Copyright (C) 2017 by Son */

using namespace std;

int main() {
	int count = 0, num;
	double a, b;
	double final_round;
	scanf("%d%lf%lf", &num, &a, &b);

	final_round = ceil(log2(num));

	while (1) {
		if (count == final_round + 1) {
			count = -1;
			break;
		}
		a = ceil(a / 2);
		b = ceil(b / 2);
		count++;
		if (a == b) {
			break;
		}
	}
	printf("%d\n", count);
	return 0;
}