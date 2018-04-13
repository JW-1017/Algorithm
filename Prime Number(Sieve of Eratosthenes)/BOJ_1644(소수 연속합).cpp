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
#include <unordered_map>
#include <unordered_set>

using namespace std;
/*

input
41

output
3

https://www.acmicpc.net/problem/1644
/* Copyright (C) 2018 by Son J.W*/

bool arr[4000001];
vector<int> v;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j, n, len, st = 0, num = 0, sum = 0;
	cin >> n;
	for (i = 2; i <= n; i++) {
		if (!arr[i]) {
			v.push_back(i);
			for (j = i; j <= n; j += i) {
				arr[j] = 1;
			}
		}
	}
	len = v.size();
	for (i = 0; i < len; i++) {
		sum += v[i];
		if (sum == n) {
			num++;
			sum -= v[st];
			st++;
		}
		else if (sum > n) {
			while (1) {
				sum -= v[st];
				st++;
				if (sum == n) {
					sum -= v[st];
					st++;
					num++;
					break;
				}
				else if (sum < n) {
					break;
				}
			}
		}
	}
	cout << num << "\n";
	return 0;
}