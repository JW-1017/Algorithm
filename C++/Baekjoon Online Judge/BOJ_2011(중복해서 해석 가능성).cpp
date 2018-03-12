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
25114

output
6

https://www.acmicpc.net/problem/2011
/* Copyright (C) 2018 by Son */

#define mod 1000000

using namespace std;

int arr[5001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j, t, len;
	string str;
	cin >> str;
	len = str.length();
	if (str[0] == '0') {
		cout << "0\n";
		return 0;
	}
	arr[0] = 1;			// �ε��� -2�� ����ϹǷ� �ε��� 1������ Ȱ���� ����
	arr[1] = 1;
	for (i = 1; i < len; i++) {
		t = i + 1;		// memo�ϴ� arr���� �����ϴ� ���� �ε��� +1
		if (str[i] == '0') {		// 0�̶�� �ι�° �տ� �ִ� ���� ����
			arr[t] = arr[t - 2];
			continue;
		}
		// 10 ���� 26�������� Ȯ��, 10�� �̹� ���� if������ �ɷ���
		j = (str[i - 1] - '0') * 10 + str[i] - '0';
		if (j > 10 && j < 27) {
			// �ι��տ������� ����� �ٷξ� ����� ��
			// 2 5 14, 2 5 1 4, 25 14, 25 1 4 ��ħ���ν� �ι�° �ձ����� ���� +
			arr[t] = (arr[t - 2] + arr[t - 1]) % mod;
		}
		else {
			// �ƴ϶�� �״�� ����
			arr[t] = arr[t - 1];
		}
	}
	cout << arr[len] << "\n";
	return 0;
}