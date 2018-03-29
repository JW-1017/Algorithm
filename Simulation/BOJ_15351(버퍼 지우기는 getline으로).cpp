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
OTAKU LIFE
PRODUCER
GAMING LIFE
PROGRAMMING

output
PERFECT LIFE
PERFECT LIFE
83
131

https://www.acmicpc.net/problem/15351
/* Copyright (C) 2018 by Son J.W*/

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j, n, len, r;
	string s;
	
	cin >> n; 
	getline(cin, s);		// 버퍼 getline 으로 지우기 (getchar는 오류남)
	for (i = 0; i < n; i++) {
		r = 0;
		getline(cin, s);
		len = s.length();
		for (j = 0; j < len; j++) {
			if (s[j] == ' ') {
				continue;
			}
			r += (s[j] - 'A' + 1);
		}
		if (r == 100) {
			cout << "PERFECT LIFE\n";
		}
		else {
			cout << r << "\n";
		}
	}
	return 0;
}