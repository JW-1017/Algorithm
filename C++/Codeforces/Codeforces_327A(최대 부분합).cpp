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
input
5
1 0 0 1 0

output
4
http://codeforces.com/contest/327/problem/A
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
bool is_square(long long n) {
	long long squareRootN = (long long)round((sqrt(n)));

	if (squareRootN*squareRootN == n) {
		return true;
	}
	else {
		return false;
	}
}
int arr[100];
int main() {
	ios::sync_with_stdio(false);
	int temp, num = 0, count = 0; 
	int tss, mss;			// tss : 자신 까지 최대 부분 합, mss : 최대 부분합 (연속적)
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> temp;
		if (temp == 1) {
			count++; arr[i] = -1;
		}
		else {
			arr[i] = 1;
		}
	}
	tss = mss = arr[0];
	for (int i = 1; i < num; i++) {
		// 현재 자신을 포함하여 이어지는 sequence의 최대합 (이전 최대핪 tss가 음수면 나 자신이 최대)
		tss = max(tss, 0) + arr[i];	
		// 구해진 합들의 최대를 갱신
		mss = max(mss, tss);
	}
	cout << mss + count << "\n";
	return 0;
}