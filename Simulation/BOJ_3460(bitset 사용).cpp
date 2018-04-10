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
#include <bitset>
#include <unordered_set>
#include <unordered_map>

/*
input
1
13

output
0 2 3

https://www.acmicpc.net/problem/3460
/* Copyright (C) 2018 by Son J.W*/

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j, c, n;
	cin >> c;
	for (i = 0; i < c; i++) {
		cin >> n;
		// 20자리 비트 생성
		const bitset<20> mask(n);
		// 뒷자리부터 차례대로 접근
		for (j = 0; j < 20; j++) {
			if (mask[j]) {
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}