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
5 0
-7 -3 -2 5 8

output
1

https://www.acmicpc.net/problem/1182
/* Copyright (C) 2018 by Son */

using namespace std;

int n, s, cnt, sum;
int arr[20];
void dfs(int cur) {
	if (cur == n) {
		return;
	}
	// ����ġ �������� ���� s �϶� count ����
	if (sum + arr[cur] == s) {
		cnt++;
	}
	// �ڽ��� �������� �ʰ� s ���� ���س���
	dfs(cur + 1);
	// �ڽ��� �����ϰ� s�� ���س���
	sum += arr[cur];
	dfs(cur + 1);
	// �ڽ��� ���� �տ� ������ �� ���س����� ���ؼ�
	sum -= arr[cur];
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j;
	cin >> n >> s;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dfs(0);
	cout << cnt << "\n";
	return 0;
}