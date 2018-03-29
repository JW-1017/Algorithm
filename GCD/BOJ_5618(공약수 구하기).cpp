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

#include <locale>

/*
input 
2
75 125

output
1
5
25

https://www.acmicpc.net/problem/5618
/* Copyright (C) 2018 by Son J.W*/

using namespace std;

// 최대공약수 구하기
int gcd(int x, int y) {
	int t;
	while (y) {
		t = x % y;
		x = y;
		y = t;
	}
	return x;
}

int arr[3];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	// 최대 공약수의 약수가 결국 공약수
	int i, n, k;
	queue<int> q;
	cin >> n;
	cin >> arr[0];
	k = arr[0];
	for (i = 1; i < n; i++) {
		cin >> arr[i];
		k = gcd(k, arr[i]);
	}
	for (i = 1; i <= k; i++) {
		if (!(k % i)) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		cout << q.front() << "\n";
		q.pop();
	}
	return 0;
}