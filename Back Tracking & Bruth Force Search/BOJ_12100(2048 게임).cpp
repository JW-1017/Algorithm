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
3
2 2 2
4 4 4
8 8 8

output
16

https://www.acmicpc.net/problem/12100
/* Copyright (C) 2018 by Son J.W*/

using namespace std;

int n, maxv;
int arr[20][20];

// 1 ���� 2 ������ 3 ���� 4 �Ʒ� ��

void solve(int s, int cnt) {
	int i, j, k, t, ind, temp[20][20];
	if (s == 1) {
		for (i = 0; i < n; i++) {
			// �־��ִ� �ε��� (�̵� ���� �պ��� ä����)
			ind = 0; t = 0;
			for (j = 0; j < n; j++) {
				if (arr[i][j] != 0) {
					// t�� ���� (�Ńx �� �������� ������ �����ϴ� ��
					t = arr[i][j];
					arr[i][j] = 0;
					j++;
					break;
				}
			}
			for ( ; j < n; j++) {
				if (arr[i][j] == 0) {
					continue;
				}
				// ���� ���� 0�̸� ���� �� �־� �ְ� 0����
				if (t == 0) {
					t = arr[i][j];
					arr[i][j] = 0;
				}
				// ���� ���� ���ٸ� ���簪 0���� �־��� ��ġ�� ���� ����
				else if (arr[i][j] == t) {
					arr[i][j] = 0;
					// ���� �� �ִ밪 ����
					arr[i][ind] = t + t;
					maxv = max(maxv, t + t);
					ind++; t = 0;
				}
				// �ٸ��� �־��� ���� ���� �� �־��ְ� t �� ����
				else {
					arr[i][ind] = t;
					ind++; t = arr[i][j];
					arr[i][j] = 0;
				}
			}
			// ���� �ִ� t���� ���� ���� (0�̾ ��� ����)
			arr[i][ind] = t;
		}
	}
	else if (s == 2) {
		for (i = n-1; i >= 0; i--) {
			ind = n-1; t = 0;
			for (j = n-1; j >= 0; j--) {
				if (arr[i][j] != 0) {
					t = arr[i][j];
					arr[i][j] = 0;
					j--;
					break;
				}
			}
			for (; j >= 0; j--) {
				if (arr[i][j] == 0) {
					continue;
				}
				if (t == 0) {
					t = arr[i][j];
					arr[i][j] = 0;
				}
				else if (arr[i][j] == t) {
					arr[i][j] = 0;
					arr[i][ind] = t + t;
					maxv = max(maxv, t + t);
					ind--; t = 0;
				}
				else {
					arr[i][ind] = t;
					ind--; t = arr[i][j];
					arr[i][j] = 0;
				}
			}
			arr[i][ind] = t;
		}
	}
	else if (s == 3) {
		for (j = 0; j < n; j++) {
			ind = 0; t = 0;
			for (i = 0; i < n; i++) {
				if (arr[i][j] != 0) {
					t = arr[i][j];
					arr[i][j] = 0;
					i++;
					break;
				}
			}
			for (; i < n; i++) {
				if (arr[i][j] == 0) {
					continue;
				}
				if (t == 0) {
					t = arr[i][j];
					arr[i][j] = 0;
				}
				else if (arr[i][j] == t) {
					arr[i][j] = 0;
					arr[ind][j] = t + t;
					maxv = max(maxv, t + t);
					ind++; t = 0;
				}
				else {
					arr[ind][j] = t;
					ind++; t = arr[i][j];
					arr[i][j] = 0;
				}
			}
			arr[ind][j] = t;
		}
	}
	else {
		for (j = n-1; j >= 0; j--) {
			ind = n - 1; t = 0;
			for (i = n - 1; i >= 0; i--) {
				if (arr[i][j] != 0) {
					t = arr[i][j];
					arr[i][j] = 0;
					i--;
					break;
				}
			}
			for (; i >= 0; i--) {
				if (arr[i][j] == 0) {
					continue;
				}
				if (t == 0) {
					t = arr[i][j];
					arr[i][j] = 0;
				}
				else if (arr[i][j] == t) {
					arr[i][j] = 0;
					arr[ind][j] = t + t;
					maxv = max(maxv, t + t);
					ind--; t = 0;
				}
				else {
					arr[ind][j] = t;
					ind--; t = arr[i][j];
					arr[i][j] = 0;
				}
			}
			arr[ind][j] = t;
		}
	}
	if (cnt == 10) {
		return;
	}
	cnt++;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			temp[i][j] = arr[i][j];
		}
	}
	for (i = 1; i <= 4; i++) {
		solve(i, cnt);
		for (k = 0; k < n; k++) {
			for (j = 0; j < n; j++) {
				arr[k][j] = temp[k][j];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j, k, temp[20][20];
	cin >> n;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> arr[i][j];
			temp[i][j] = arr[i][j];
			maxv = max(arr[i][j], maxv);
		}
	}
	for (i = 1; i <= 4; i++) {
		solve(i, 1);
		for (k = 0; k < n; k++) {
			for (j = 0; j < n; j++) {
				arr[k][j] = temp[k][j];
			}
		}
	}
	cout << maxv << "\n";
	return 0;
}