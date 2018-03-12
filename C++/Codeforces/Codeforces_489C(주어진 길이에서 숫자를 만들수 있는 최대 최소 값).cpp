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
���� m(ex 2), �� s(ex 15)�� ����� �ִ� ���� �ִ� �ּ�
input
2 15

output
69 96

http://codeforces.com/problemset/problem/489/C
/* Copyright (C) 2018 by Son */

using namespace std;

long repeated_squaring(long base, long exp)
{
	long result = 1;
	while (exp) {		// not zero
		if (exp % 2) {		// remain == 1
			result *= base;
		}
		base *= base;
		exp = exp /= 2;
	}
	return result;
}
vector<int> int_to_vector(long long num)
{
	vector<int> v;
	while (1) {
		if (num == 0) {
			return v;
		}
		v.insert(v.begin(), num % 10);
		num /= 10;
	}
}
string replace_all(const string& message, const string& pattern, const string& replace) {
	string result = message;
	string::size_type pos = 0;
	string::size_type offset = 0;
	int p_len = pattern.length();
	int r_len = replace.length();

	while ((pos = result.find(pattern, offset)) != string::npos) {
		result.replace(result.begin() + pos, result.begin() + pos + p_len, replace);
		offset = pos + r_len;
	}
	return result;
}
int main() {
	ios::sync_with_stdio(false);
	bool flag1 = 0, flag2 = 0;
	int m, s, s2;
	cin >> m >> s;
	s2 = s;
	int* max_val = new int[m];
	int* min_val = new int[m];

	// �ִ� ���� �ڸ�����ŭ ���� ���� s���� �۰ų� s�� 0 �ε� ���̰� 1�� �ƴҶ�
	if (m * 9 <  s || (s == 0 && m != 1)) {
		cout << "-1 -1\n";
		return 0;
	}
	for (int j = 0; j < m; j++) {
		// flag1 �� max_val �����Ϸῡ ���� ��, flag2 �� min_val �����Ϸῡ ���� ��
		// s(max_val���� ����ϴ� ��ǥ ��) �� 0�� ������ �������� 0���� ä��
		if (s == 0 && !flag1) {
			for (int i = j; i < m; i++) {
				max_val[i] = 0;
			}
			// flag1 ������ ���� ���̻� ���� ����
			flag1 = 1;
		}
		// 0��° ��ġ�� ����(min_val�� �ڿ��� ���� ä��) �ش� ���� ������ ������
		if (j == m - 1 && !flag2) {
			min_val[0] = s2;
			// flag2 ������ ���� ���̻� ���� ����
			flag2 = 1;
		}
		// s2(min_val���� ����ϴ� ��ǥ ��)�� 1�� ������ ������ 0���� ä��� �� ���ڸ� 1
		else if (s2 == 1 && !flag2) {
			for (int i = m - j - 1; i > 0; i--) {
				min_val[i] = 0;
			}
			// ó�� �� 1
			min_val[0] = 1;
			flag2 = 1;
		}
		// ���� max_val�� ���� ������ ������ ������
		if (!flag1) {
			for (int i = 9; i > 0; i--) {
				// 9���� �����ؼ� 0���� �ٿ������� ���� ����(�տ��� ���� ū �� ����)
				if (s - i >= 0) {
					s -= i;
					max_val[j] = i;
					break;
				}
			}
		}
		// ���� min_val�� ���� ������ ������ ������
		if (!flag2) {
			for (int i = 9; i >= 1; i--) {
				// 9���� �����ؼ� 1���� �ٿ������� ���� ����(�ڿ��� ���� ū �� ����)
				if (s2 - i > 0) {
					// 0�� �� ���� ���� ó������
					min_val[m - j - 1] = i;
					s2 -= i;
					break;
				}
			}
		}
		if (flag1 && flag2) {
			break;
		}
	}
	for (int i = 0; i < m; i++) {
		cout << min_val[i];
	}
	cout << " ";
	for (int i = 0; i < m; i++) {
		cout << max_val[i];
	}
	cout << "\n";
	return 0;
}