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
7

output
1213121

https://www.acmicpc.net/problem/2661
/* Copyright (C) 2018 by Son */

using namespace std;

string str = "12";
int n;

bool solve(int l) {
	int num = 2;
	string temp = "", temp2 = "";
	temp += str[l - 1];
	temp2 += str[l - 2];
	// ������ �ٿ����鼭 Ȯ�� (�� �������� Ȯ���ϴϱ�)
	while (1) {
		if (temp == temp2) {
			return 0;
		}
		// �ش� ���̸� �Ѿ �� (�տ� num���� �� �ϱ� �� index�� �Ѿ������)
		if (l - num - num < 0) {
			break;
		}
		// �ٷξ� character ���̱�
		temp = str[l-num] + temp;
		temp2 = "";
		// ���� ���� ���ڿ�
		for (int s = 0; s < num; s++) {
			temp2 += str[l - num - s - 1];
		}
		// ������
		reverse(temp2.begin(), temp2.end());
		num++;
	}
	if (l == n) {
		return 1;
	}
	for (char i = '1'; i <= '3'; i++) {
		str += i;
		// �ٿ�����
		if (solve(l + 1)) {
			return 1;
		}
		// ����
		str = str.substr(0, l);
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	if (n == 1) {
		cout << "1\n";
		return 0;
	}
	solve(2);
	cout << str << "\n";

	return 0;
}