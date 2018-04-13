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
/*
ó�� �������� ���� ��� �ּҰ��� ����� �Ȱ���!!
(�̰� ������ �����, �ᱹ ���ƿ��� ��α� ����)

�ش� ������ ���� �湮��ġ(��Ʈ�� ����)�� �����ذ��� Ǯ��

input
10 15
5 1 3 5 10 7 4 9 2 8

output
2

https://www.acmicpc.net/problem/1806
/* Copyright (C) 2018 by Son J.W*/

using namespace std;
int arr[100000];
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j, n, num = 0, minv = 100000, st;
	long long m, sum = 0;
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	st = 0;
	sum += arr[0];
	num++;
	// ������ ���� �ִ밡 �Ǹ� 1���
	if (sum >= m) {
		cout << "1\n";
		return 0;
	}
	for (i = 1; i < n; i++) {
		sum += arr[i];
		num++;
		// sum�� m���� ũ�ų� ������
		if (sum >= m) {
			do {
				sum -= arr[st];
				// �۾��� �� ���� ����
				if (sum < m) {
					// ������ ���� ũ�ų� ���� ��
					sum += arr[st];
					break;
				}
				num--;
				st++;
			} while (sum >= m);
			minv = min(minv, num);
		}
	}
	if (minv == 100000) {
		minv = 0;
	}
	cout << minv << "\n";
	return 0;
}