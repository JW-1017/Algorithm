#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <map>
#include <set>
#include <list>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <numeric>
#include <cmath>
#include <unordered_set>
#include <unordered_map>

#pragma warning(disable:4996)

/*
input
1 2 4 4
2 3 5 7
3 1 6 5
7 3 8 6

output
26

https://www.acmicpc.net/problem/2669
/* Copyright (C) 2018 by Son */

using namespace std;

bool arr[101][101];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j, w, a, b, c, d, s = 0;
	for (i = 0; i < 4; i++) {
		cin >> a >> b >> c >> d;
		// x��ǥ�� ��, y��ǥ�� ��
		// arr[x][y] �� �ڽ��� ������ x+1, y+1���� ���� 1¥�� �簢��
		// ���� ������ ���� ��
		for (j = b; j < d; j++) {
			for (w = a; w < c; w++) {
				if (!arr[j][w]) {
					s++;
				}
				arr[j][w] = 1;
			}
		}
	}
	cout << s << "\n";
	return 0;
}