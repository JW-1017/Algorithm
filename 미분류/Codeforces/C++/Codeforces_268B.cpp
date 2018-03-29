#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <numeric>

/*
input
3

output
7

http://codeforces.com/problemset/problem/268/B

count fail push for right way 
if num == 3 and right way is 1 2 3

worst case scenario
3
2 -> 2		// fisrt
1  3 -> 2	
   2  1 -> 3	// last find
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
		exp = exp >> 1;
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
	int num;
	int count = 0;
	cin >> num;

	// fisrt step push num - 1, last step push num 
	count += num - 1 + num;
	for (int i = 2; i < num; i++) {
		// i step num - i case
		count += (i * (num - i));
	}
	cout << count << "\n";

	return 0;
}