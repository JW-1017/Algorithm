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
10 3
1 2 3

output
0

https://www.acmicpc.net/problem/1021
/* Copyright (C) 2018 by Son */

using namespace std;

int arr[50];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, n, m, num = 0, temp;
	cin >> n >> m;

	deque<int> dq;
	deque<int>::iterator it;
	for (i = 1; i <= n; i++) {
		dq.push_back(i);
	}
	for (i = 0; i < m; i++) {
		cin >> arr[i];
	}
	i = 0;
	while (1) {
		if (i == m) {
			break;
		}
		if (dq.front() == arr[i]) {
			dq.pop_front();
			i++;
			continue;
		}
		// binary search(lower_bound 등) 안됨(정렬되어 있지 않음)
		it = find(dq.begin(), dq.end(), arr[i]);
		// 앞쪽과 더 가까우면 앞쪽 pop
		if (it - dq.begin() <= dq.end() - 1 - it) {
			while(1) {
				num++;
				temp = dq.front();
				dq.pop_front();
				dq.push_back(temp);
				if (dq.front() == arr[i]) {
					dq.pop_front();
					i++;
					break;
				}
			}
		}
		// 뒤쪽과 더 가까우면 뒤쪽 pop
		else {
			while (1) {
				num++;
				temp = dq.back();
				dq.pop_back();
				dq.push_front(temp);
				if (dq.front() == arr[i]) {
					dq.pop_front();
					i++;
					break;
				}
			}
		}
	}
	cout << num << "\n";
	return 0;
}