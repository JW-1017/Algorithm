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
5 2
BGGBG

output
GGBGB

http://codeforces.com/problemset/problem/266/B

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

int main() {
	std::ios::sync_with_stdio(false);
	int n, t;
	string str;
	
	cin >> n >> t;
	cin >> str;
	int len = str.length();

	string s(len, 'G');
	// 끝 인덱스는 변하지 않으므로 기록
	s[len - 1] = str[len - 1];
	queue<int> que1;
	// queue에 B의 위치 기록
	for (int j = 0; j < len - 1; j++) {
		if (str[j] == 'B') {
			que1.push(j);
		}
	}
	for (int i = 0; i < t; i++) {
		len = que1.size();
		for (int j = 0; j < len; j++) {
			char temp = que1.front(); que1.pop();
			// 다음 인덱스가 G 일때 swap 및 다시 위치 기록
			if (str[temp + 1] == 'G') {
				str[temp] = 'G';
				str[temp + 1] = 'B';
				que1.push(temp + 1);
				continue;
			}
			que1.push(temp);	// 아니면 그대로 큐 뒤에
		}
	}
	// 마지막 큐 인덱스 따라 B 입력
	while (!que1.empty()) {
		s[que1.front()] = 'B';
		que1.pop();
	}
	cout << s << "\n";
	return 0;
}