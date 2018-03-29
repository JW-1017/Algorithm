#include <cstdio>
#include <cmath>

#pragma warning(disable:4996)
/*
input
2
-5 1 12 1
7
1 1 8
-3 -1 1
2 2 2
5 5 1
-4 5 1
12 1 1
12 1 2
-5 1 5 1
1
0 0 2

output
3
0

https://www.acmicpc.net/problem/1004

/* Copyright (C) 2017 by Son */

using namespace std;

double get_dis(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
	int i, k, t_case, num, x1, y1, x2, y2;
	int x3, y3, r, count;
	double dis1, dis2, dis3;
	scanf("%d", &t_case);

	for (k = 0; k < t_case; k++) {
		count = 0;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		scanf("%d", &num);

		for (i = 0; i < num; i++) {
			scanf("%d%d%d", &x3, &y3, &r);
			dis1 = get_dis(x3, y3, x1, y1);
			dis2 = get_dis(x3, y3, x2, y2);
			dis3 = r;

			if (dis1 <= dis3 && dis2 <= dis3) {}
			else if (dis1 <= dis3) {
				count++;
			}
			else if (dis2 <= dis3) {
				count++;
			}
			else{}
		}
		printf("%d\n", count);
	}
	return 0;
}