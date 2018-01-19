#include <cstdio>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

/*
input
9
1 2 1 3 2 2 2 2 3

output
10

http://codeforces.com/problemset/problem/455/A

/* Copyright (C) 2018 by Son */

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
priority_queue<int> int_to_pq(long long num)
{
	priority_queue<int> pq;
	while (1) {
		if (num == 0) {
			return pq;
		}
		pq.push(num % 10);
		num /= 10;
	}
}
long long sum[100002];
long long result[2][100002];	// 0 -> ���Խ�Ŵ, 1-> ���ԾȽ�Ŵ
int main() {
	std::ios::sync_with_stdio(false);
	int i = 0;
	int max_v = 0;
	int min_v = 100010;

	int n;
	cin >> n;
	
	for (i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		sum[temp] += temp;
		max_v = max(max_v, temp);
		min_v = min(min_v, temp);
	}
	result[0][min_v] = sum[min_v];
	result[1][min_v] = 0;
	result[0][min_v+1] = sum[min_v+1];
	result[1][min_v+1] = sum[min_v];
	result[0][min_v + 2] = sum[min_v + 2] + sum[min_v];
	result[1][min_v + 2] = sum[min_v+1];
	for (i = min_v+3; i <= max_v; i++) {
		result[0][i] = max(result[0][i - 2] + sum[i], result[0][i - 3] + sum[i]);		// ��ĭ���� ���ڽ� , ��ĭ���� ���ڽ� ��
		result[1][i] = result[0][i - 1];			// �ٷ� ������ ���Ծ��� ��
	}
	cout << max(result[0][max_v], result[1][max_v]) << "\n";
	return 0;
}