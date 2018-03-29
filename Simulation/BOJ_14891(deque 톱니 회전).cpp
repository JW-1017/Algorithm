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
10001011
10000011
01011011
00111101
5
1 1
2 1
3 1
4 1
1 -1

output
6

https://www.acmicpc.net/problem/14891
/* Copyright (C) 2018 by Son J.W*/

using namespace std;

#define LEFT 6
#define RIGHT 2

vector<deque<bool>> a;

void rotate(int c, int flag) {
	bool temp;
	if (flag == 1) {
		temp = a[c].back(); a[c].pop_back(); a[c].push_front(temp);
	}
	else {
		temp = a[c].front(); a[c].pop_front(); a[c].push_back(temp);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j, n, c, d, temp, num;
	string s;

	a = vector<deque<bool>>(4);

	for (i = 0; i < 4; i++) {
		cin >> s;
		for (j = 0; j < 8; j++) {
			a[i].push_back((bool)(s[j] - '0'));
		}
	}
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> c >> d;
		c--;
		temp = -d;
		if (c - 1 != -1){
			for (j = c - 1; j >= 0; j--) {
				if (a[j][RIGHT] == a[j + 1][LEFT]) {
					break;
				}
			}
			num = j + 1;
			for (j = c - 1; j >= num; j--) {
				rotate(j, temp);
				temp *= -1;
			}
		}
		temp = -d;
		if(c + 1 != 4) {
			for (j = c + 1; j < 4; j++) {
				if (a[j - 1][RIGHT] == a[j][LEFT]) {
					break;
				}
			}
			num = j - 1;
			for (j = c + 1; j <= num; j++) {
				rotate(j, temp);
				temp *= -1;
			}
		}
		rotate(c, d);
	}
	cout << a[0][0] + a[1][0] * 2 + a[2][0] * 4 + a[3][0] * 8 << "\n";
	return 0;
}