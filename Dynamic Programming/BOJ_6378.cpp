#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cctype>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <functional>
#include <algorithm>
#include <cstdlib>

using namespace std;

/*

input:
24
39
0

output:
6
3

https://www.acmicpc.net/problem/6378

/* Copyright (C) 2018 by Son */

unordered_map<string, int> dp;

int main(){
	ios::sync_with_stdio(false); cin.tie(0);

	int i, len, sum;
	string num;

	while (1) {
		cin >> num;
		if (num == "0") {
			break;
		}
		sum = 0;
		len = num.length();
		for (i = 0; i < len; i++) {
			sum += num[i] - '0';
		}
		num = to_string(sum);
		if (num.length() == 1) {
			cout << num << "\n";
			continue;
		}
		while ((len =  num.length()) != 1) {
			if (dp.find(num) != dp.end()) {
				sum = dp[num];
			}
			else {
				sum = 0;
				for (i = 0; i < len; i++) {
					sum += num[i] - '0';
				}
				dp[num] = sum;
			}
			num = to_string(sum);
		}
		cout << num << "\n";
	}
	return 0;
}