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

#pragma warning(disable:4996)

/*
1 2 3 4 5
11 22 33 44 55
1111 2222 3333 4444 5555
...
�̷� �������� n��° ��ġ�� �� ã��

input
1802

output
Penny

http://codeforces.com/problemset/problem/82/A
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
int max_continuos_sum(int* arr, int n) {
	int tss = arr[0];
	int mss = arr[0];
	for (int i = 1; i < n; i++) {
		tss = max(tss, 0) + arr[i];
		mss = max(tss, mss);
	}
	return mss;
}
int arr[28];
int main() {
	ios::sync_with_stdio(false);
	int i, n, val = 1;
	string str[6] = {"", "Sheldon", "Leonard", "Penny", "Rajesh", "Howard" };
	cin >> n;

	// 5���� �۰ų� ������ ���ڸ� �״��
	if (n <= 5) {
		cout << str[n] << "\n";
	}
	else {
		// ���� 5�� �����
		n -= 5;
		// arr[i]�� i��° ������ �ڸ� �ε����� ����
		for (i = 1; i <= 27; i++) {
			val *= 2;
			// 10 * (2^n - 1) ��
			arr[i] = 10 * (val - 1);
			// ������ �ε������� ������ break;
			if (n < arr[i]) {
				break;
			}
		}
		// ��ǥ �ε������� ���� ������ ������ �ε��� ���� ����
		n -= arr[i - 1];
		// �� ������ ������� Ȯ��
		val = (arr[i] - arr[i - 1]) / 5;
		for (i = 1; i <= 5; i++) {
			if (n <= val*i) {
				// �� �ϸ� ���籸������ ���°���� Ȯ��
				cout << str[i] << "\n";
				break;
			}
		}
	}
	return 0;
}