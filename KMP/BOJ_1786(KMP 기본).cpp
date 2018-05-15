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
#include <deque>
#include <stack>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>

using namespace std;
/*
input:
ABC ABCDAB ABCDABCDABDE
ABCDABD

output:
1
16

https://www.acmicpc.net/problem/1786
/* Copyright (C) 2018 by Son J.W*/

int n, m;
int pi[1000000];
vector<int> ans;

void getPi(string p) {
	int i, j = 0; m = p.size();
	for (i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j]) {
			j = pi[j - 1];
		}
		if (p[i] == p[j]) {
			pi[i] = ++j;
		}
	}
}

void kmp(string s, string p) {
	int i, j = 0;
	n = s.size();
	getPi(p);
	for (i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j]) {
			j = pi[j - 1];
		}
		if (s[i] == p[j]) {
			if (j == m - 1) {
				// ans.push_back(i - m + 1);
				ans.push_back(i - m + 2);		// 원래 i - m + 1인데 1부터 index라 +1
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	string s, p;
	getline(cin, s);
	getline(cin, p);
	kmp(s, p);

	cout << ans.size() << "\n";
	for (auto& k : ans) {
		cout << k << " ";
	}
	return 0;
}