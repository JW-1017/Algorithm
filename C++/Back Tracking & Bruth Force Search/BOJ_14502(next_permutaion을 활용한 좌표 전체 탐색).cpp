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
7 7
2 0 0 0 1 1 0
0 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 0 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0

output
27

https://www.acmicpc.net/problem/14502
/* Copyright (C) 2018 by Son */

using namespace std;

/*
next_permutation�� Ȱ���Ͽ� 1�� �� �� �ִ� ��� ��ġ Ž��
1 ���� ������ 0���� (��ǥ�� 1�ڸ���)
*/

int n, m, cnt;
int arr[8][8];
int temp[8][8];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void solve2(int x, int y) {
	int i, a, b;
	for (i = 0; i < 4; i++) {
		a = x + dx[i], b = y + dy[i];
		if (a != -1 && a != n && b != -1 && b != m && !temp[a][b]) {
			// ���� ���� ��ġ 3����
			cnt--;
			temp[a][b] = 3;
			solve2(a, b);
		}
	}
}
void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// 2�� �� ���� �� �ٲٰ� ��� (2�϶��� �� ���� �ϸ� �ȵ� �̹� ���ҽ�Ų ä�� ������ ���)
			if (temp[i][j] == 2) {
				temp[i][j] = 3;
				solve2(i, j);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j, num = 0, result = 0;
	vector<int> xy;
	bool* sol;
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (!arr[i][j]) {
				xy.push_back(i*m + j);		// xy ��ġ�� 0�� ��ġ
				num++;			// 0�� ���� (2�� ���� �� 1�� ���� �� ����)
			}
		}
	}
	sol = new bool[num];		// �ʱ�ȭ ����ߵ�
 	memset(sol, 0, num);
	sol[0] = 1; sol[1] = 1; sol[2] = 1;		// sol�� 1�̵Ǵ� �ε����� xy������ ��ǥ ����
	do {
		cnt = num - 3;		// �� 3�� �δϱ�
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				temp[i][j] = arr[i][j];		// ����� ���� (���� �����)
			}
		}
		for (i = 0; i < num; i++) {
			if (sol[i]) {					
				temp[xy[i] / m][xy[i] % m] = 1;
			}
		}
		solve();
		result = max(result, cnt);
	} while (prev_permutation(sol, sol + num));
	cout << result << "\n";
	return 0;
}