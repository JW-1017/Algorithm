#include <cstdio>
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
0 0 0 0 0
0 0 0 0 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0

output
3

http://codeforces.com/problemset/problem/263/A

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
	
	int i, j, temp, x, y;
	int count = 0;

	for (i = 1; i <= 5; i++) {
		for (j = 1; j <= 5; j++) {
			cin >> temp;
			if (temp == 1) {
				x = j;
				y = i;
			}
		}
	}
	temp = (y-1) * 5 + x;
	if (temp > 13) {
		count += (y - 3 + abs(x - 3));
	}
	else if (temp < 13) {
		count += (3 - y + abs(x - 3));
	}
	cout << count << "\n";
	return 0;
}