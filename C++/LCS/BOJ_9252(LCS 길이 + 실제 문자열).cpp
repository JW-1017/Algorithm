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
ACAYKP
CAPCAK

output
4
ACAK

https://www.acmicpc.net/problem/9252
/* Copyright (C) 2018 by Son */

using namespace std;

bool flag[1001][1001];
int dp[1001][1001];
pair<int, int> pr[1001][1001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j, maxv = 0, a = 0, b = 0;
	string s1, s2, result = ""; 
	cin >> s1 >> s2;

	int len1 = s1.length();		// ���� ����
	int len2 = s2.length();		// ���� ���� (�� �����ϸ� ���ι��� �ϳ� �ϳ� ��)
	for (i = 1; i <= len2; i++) {
		for (j = 1; j <= len1; j++) {
			// ������
			if (s2[i - 1] == s1[j - 1]) {
				// �������� flag
				flag[i][j] = 1;
				// ���� ����
				dp[i][j] = dp[i - 1][j - 1] + 1;
				// �տ��� ������ �ڱ� �ڽ� ����
				if (pr[i-1][j-1].first == 0 || pr[i-1][j-1].second == 0) {
					pr[i][j].first = i;
					pr[i][j].second = j;
				}
				else {
					// �÷��� ������ ���� ����� flag �κ� ���ڿ�
					if (flag[i - 1][j - 1]) {
						pr[i][j] = pair<int, int>(i - 1, j - 1);
					}
					// ������ �밢�� �κ� ���ܿ���
					else {
						pr[i][j] = pr[i - 1][j - 1];
					}
				}
				// ���� ��
				if (maxv < dp[i][j]) {
					maxv = dp[i][j];
					// ���� �� ���� �� ���ڿ��� ������ ����
					a = i; b = j;
				}
			}
			else {
				// �ٸ��� �������� 
				if (dp[i - 1][j] > dp[i][j - 1]) {
					dp[i][j] = dp[i - 1][j];
					// �÷��� ������ �ش� �ڸ�
					if (flag[i - 1][j]) {
						pr[i][j] = pair<int, int>(i - 1, j);
					}
					// ������ ���� ���ܿ�
					else {
						pr[i][j] = pr[i - 1][j];
					}
				}
				else {
					dp[i][j] = dp[i][j - 1];
					// �÷��� ������ �ش� �ڸ�
					if (flag[i][j - 1]) {
						pr[i][j] = pair<int, int>(i, j - 1);
					}
					// ������ ���� ���ܿ�
					else {
						pr[i][j] = pr[i][j - 1];
					}
				}
			}
		}
	}
	result = s2[a - 1];
	while (1) {
		i = pr[a][b].first;
		j = pr[a][b].second;
		// ������ Ż��
		if (i == a && j == b) {
			break;
		}
		result = s2[i - 1] + result;
		a = i, b = j;
	}
	cout << maxv << "\n";
	cout << result << "\n";
	return 0;
}