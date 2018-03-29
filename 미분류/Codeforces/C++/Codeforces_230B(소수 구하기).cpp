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

/*
input
3
4 5 6

output
YES
NO
NO

http://codeforces.com/problemset/problem/230/B
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
int main() {
	ios::sync_with_stdio(false);
	bool flag = true;
	long long i, j, n, k;
	long long temp;
	unordered_set<long long> s;
	unordered_set<long long> t_prime;
	// �����佺�׳׽��� ü (�Ҽ� ���ϱ�)
	for (i = 2; i < 1e6; i++) {
		// �Ҽ��̸� (prime number�� �ƴ� ���� ���� set�ȿ� ������)
		if (s.find(i) == s.end()) {		
			k = i + i;			// ���� ������
			for(j = k; j < 1e6; j+=i){		// ����ϸ� ����
				s.insert(j);
			}
			// t_prime���� �ᱹ 3���� ����� �����µ� 2���� ������ 1�� �ڽ� �׸��� 1���� ������ �Ǽ� �ڽ��� �Ǵ¼�
			// ���� prime �� ������ü�� t_prime���̴�.
			t_prime.insert(i*i);		
		}
	}
	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> temp;
		if (t_prime.find(temp) != t_prime.end()) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}