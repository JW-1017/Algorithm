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

/*
input
WUBWEWUBAREWUBWUBTHEWUBCHAMPIONSWUBMYWUBFRIENDWUB

output
WE ARE THE CHAMPIONS MY FRIEND

http://codeforces.com/problemset/problem/208/A

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
		// 현재 offset자리에 바로 WUB발견 안될때만 스페이스
		if (pos != offset) {
			result.replace(result.begin() + pos, result.begin() + pos + p_len, " ");
			// offset + 1(space 추가 됐으므로)
			offset = pos + r_len + 1;
		}
		else {
			result.replace(result.begin() + pos, result.begin() + pos + p_len, "");
			offset = pos + r_len;
		}
	}
	return result;
}
int main() {
	ios::sync_with_stdio(false);
	string str;
	string result;
	cin >> str;

	result = replace_all(str, "WUB", "");
	int len = result.length();
	// 끝에 WUB로 안끝나면 space 없음
	if (result[len - 1] != ' ') {
		result += " ";
	}
	cout << result;

	return 0;
}