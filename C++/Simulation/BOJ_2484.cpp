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

/*
input 
4
3 3 3 3
3 3 6 3
2 2 6 6
6 2 1 5

output
65000

https://www.acmicpc.net/problem/2484
/* Copyright (C) 2018 by Son J.W*/

using namespace std;
pair<int, int> arr[7];		// 첫번째가 갯수 두번째가 눈금
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j, n, mav = 0, vr, temp;
	
	cin >> n;
	for (i = 0; i < n; i++) {
		for (j = 1; j < 7; j++) {
			arr[j].first = 0;
			arr[j].second = 0;
		}
		for (j = 0; j < 4; j++) {
			cin >> temp;
			arr[temp].first++;
			arr[temp].second = temp;
		}
		sort(arr + 1, arr + 7, greater<pair<int, int>>());
		if (arr[1].first == 4) {
			vr = 50000 + arr[1].second * 5000;
		}
		else if (arr[1].first == 1) {
			vr = arr[1].second * 100;
		}
		else if (arr[1].first == 3) {
			vr = 10000 + arr[1].second * 1000;
		}
		else {
			if (arr[2].first == 2) {
				vr = 2000 + arr[1].second * 500 + arr[2].second * 500;
			}
			else {
				vr = 1000 + arr[1].second * 100;
			}
		}
		mav = max(mav, vr);
	}
	cout << mav << "\n";
	return 0;
}