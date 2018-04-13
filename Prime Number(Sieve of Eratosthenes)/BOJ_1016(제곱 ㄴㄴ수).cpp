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
#include <unordered_map>
#include <unordered_set>
/*

input
1 10

output
7

https://www.acmicpc.net/problem/1016
/* Copyright (C) 2018 by Son J.W*/

using namespace std;

bool sosu[1000001];
bool res[1000001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int j, cnt;
	long long i, k, a, b, c, d;
	cin >> a >> b;
	// ��ü �������� �������� ������ �������� ���� ��
	cnt = (int)(b - a + 1);
	for (i = 2; i <= 1000000; i++) {
		if (!sosu[i]) {
			// �Ҽ� ������ ���� �ٷ�
			c = i * i;
			if (c > b) {
				break;
			}
			// �����佺�׳׽��� ü
			for (j = 2; ; j++) {
				d= i*j;
				if (d > 1000000 || d > b) {
					break;
				}
				sosu[d] = 1;
			}
			// �ʱ� ���� ���� Ŀ������ �ٿ�������
			for (k = (((a-1)/c) + 1)*c; k <= b; k += c) {
				if (!res[k - a]) {
					res[k - a] = 1;
					cnt--;
				}
			}
		}
	}
	cout << cnt << "\n";
	return 0;
}