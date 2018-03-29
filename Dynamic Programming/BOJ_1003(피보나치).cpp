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
3
0
1
3

output
1 0
0 1
1 2

https://www.acmicpc.net/problem/1003
/* Copyright (C) 2018 by Son J.W*/

using namespace std;

// 0행에 0의 개수 1행에 1의개수
// 앞에 두수의 0의 개수의 합, 1의 개수의 합으로 바뀜
int arr[2][41];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int j, i = 0, n, m;
	arr[0][0] = 1;
	arr[1][1] = 1;
	cin >> m;

	for (j = 0; j < m; j++) {
		cin >> n;
		if (arr[0][n] || arr[1][n]) {
			cout << arr[0][n] << " " << arr[1][n] << "\n";
			continue;
		}
		for (i = 2; i <= n; i++) {
			arr[0][i] = arr[0][i-1] + arr[0][i-2];
			arr[1][i] = arr[1][i-1] + arr[1][i-2];
		}
		cout << arr[0][n] << " " << arr[1][n] << "\n";
	}
	return 0;
}