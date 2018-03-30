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
Find Cycle

input
4 4
YYYR
BYBY
BBBY
BBBY

output
Yes

http://codeforces.com/contest/510/problem/B
/* Copyright (C) 2018 by Son J.W*/

using namespace std;

// ���߿� SCC �����ϰ� �ٽ� Ǯ��

int n, m;
// 4���� ����
int dir[4];
int arr[50][50];
// �ٷ� ���� ��ǥ�� �ȵ��ư��� ���� (x��ǥ +1 �϶� x��ǥ -1�� ��� ����)
int loc[5] = { 1, 0, 3, 2, -1 };
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
// ������ ���� �����ϴ� set
unordered_set<int> s;

int solve2(int x, int y, int t, int k) {
	// ���� ��ġ �߰�
	s.insert(x*m + y);
	// -������ ����
	arr[x][y] = -t;
	bool flag;
	int i, a, b;
	for (i = 0; i < 4; i++) {
		// �ٷ� �������̸� �Ѿ
		if (loc[k] == i) {
			continue;
		}
		// �̹� �ش� ��ġ dir���� 1���� ���� �Ǿ��ִ��� Ȯ���ϴ� flag
		flag = 1;
		a = x + dx[i];
		b = y + dy[i];
		if (a != -1 && b != -1 && a != n && b != m) {
			// -�� �� ��
			if (arr[a][b] == -t) {
				// �̹� setting �Ǿ������� flag 0���� (��Ʈ��ŷ�� ����)
				if (dir[i] == 1) {
					flag = 0;
				}
				dir[i] = 1;
				if (dir[0] && dir[1] && dir[2] && dir[3]) {
					// 4���� ��� ������ ��
					return 1;
				}
				// ���õǾ� ���� ���� �����϶� 0 ���� �ٽ�
				if (flag) {
					dir[i] = 0;
				}
			}
			else if (arr[a][b] == t) {
				// �Ȱ��� ���Ⱚ Ȯ��
				if (dir[i] == 1) {
					flag = 0;
				}
				dir[i] = 1;
				if (solve2(a, b, t, i)) {
					return 1;
				}
				// �� �ǵ����� ���Ⱚ �ǵ����� (��Ʈ��ŷ)
				arr[a][b] = t;
				if (flag) {
					dir[i] = 0;
				}
			}
		}
	}
	return 0;
}
void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s.find(i*m+j) == s.end()) {
				// ���� k ��ġ�� ���ǹ��Ѱ�����
				if (solve2(i, j, arr[i][j], 4)) {
					cout << "Yes\n";
					return;
				}
				memset(dir, 0, sizeof(dir));
			}
		}
	}
	cout << "No\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j;
	string s;
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		cin >> s;
		for (j = 0; j < m; j++) {
			arr[i][j] = s[j] - 'A' + 1;
		}
	}
	solve();
	
	return 0;
}