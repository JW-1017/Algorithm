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
7 15
15 5 3 7 9 14 0

output
2.5000000000

http://codeforces.com/problemset/problem/492/B
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
int gcd(int a, int b) {
	int temp;
	while (b != 0) {
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
class jw {
public:
	int st;
	int bo;
	jw() {}
	jw(int st, int bo) {
		this->st = st;
		this->bo = bo;
	}
	bool operator <(jw& a) {
		return this->st < a.st;
	}
	bool operator >(jw& a) {
		return this->st > a.st;
	}
	bool operator ==(jw& a) {
		return this->st == a.st;
	}
	bool operator <=(jw& a) {
		return this->st <= a.st;
	}
	bool operator >=(jw& a) {
		return this->st >= a.st;
	}
};
double arr[1000];
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i = 0, j, s, n;
	double d, temp1, temp2, m;

	cin >> n >> m;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);			// 작은 것부터 차근 차근 나아감
		
	d = arr[0] - 0.0;			// 시작위치부터 처음 가로등 까지 거리
	for (i = 1; i < n; i++) {
		temp1 = (arr[i] - arr[i - 1]) / 2.0;		// 중간 위치가 가로등 위치(둘다 밝히므로)
		d = max(d, temp1);				// 최대 값으로 설정
	}
	temp2 = m - arr[n - 1];				// 끝위치부터 마지막 가로등 거리
	d = max(d, temp2);					// 재설정
	cout << fixed;		// 소수점을 고정하겠다.
	cout.precision(10);			// 몇자리를
	cout << d << "\n";
	return 0;
}