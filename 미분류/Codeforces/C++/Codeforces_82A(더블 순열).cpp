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
이런 순열에서 n번째 위치의 값 찾기

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

	// 5보다 작거나 같으면 그자리 그대로
	if (n <= 5) {
		cout << str[n] << "\n";
	}
	else {
		// 앞의 5개 지우고
		n -= 5;
		// arr[i]에 i번째 마지막 자리 인덱스를 넣음
		for (i = 1; i <= 27; i++) {
			val *= 2;
			// 10 * (2^n - 1) 임
			arr[i] = 10 * (val - 1);
			// 마지막 인덱스보다 작으면 break;
			if (n < arr[i]) {
				break;
			}
		}
		// 목표 인덱스에서 이전 구간의 마지막 인덱스 값을 빼고
		n -= arr[i - 1];
		// 각 구간이 몇개씩인지 확인
		val = (arr[i] - arr[i - 1]) / 5;
		for (i = 1; i <= 5; i++) {
			if (n <= val*i) {
				// 비교 하며 현재구간에서 몇번째인지 확인
				cout << str[i] << "\n";
				break;
			}
		}
	}
	return 0;
}