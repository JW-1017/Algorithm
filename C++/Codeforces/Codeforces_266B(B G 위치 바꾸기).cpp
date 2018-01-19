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
	// �� �ε����� ������ �����Ƿ� ���
	s[len - 1] = str[len - 1];
	queue<int> que1;
	// queue�� B�� ��ġ ���
	for (int j = 0; j < len - 1; j++) {
		if (str[j] == 'B') {
			que1.push(j);
		}
	}
	for (int i = 0; i < t; i++) {
		len = que1.size();
		for (int j = 0; j < len; j++) {
			char temp = que1.front(); que1.pop();
			// ���� �ε����� G �϶� swap �� �ٽ� ��ġ ���
			if (str[temp + 1] == 'G') {
				str[temp] = 'G';
				str[temp + 1] = 'B';
				que1.push(temp + 1);
				continue;
			}
			que1.push(temp);	// �ƴϸ� �״�� ť �ڿ�
		}
	}
	// ������ ť �ε��� ���� B �Է�
	while (!que1.empty()) {
		s[que1.front()] = 'B';
		que1.pop();
	}
	cout << s << "\n";
	return 0;
}