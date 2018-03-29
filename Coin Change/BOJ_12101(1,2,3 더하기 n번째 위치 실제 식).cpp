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
4 5

output
2+1+1

https://www.acmicpc.net/problem/12101
/* Copyright (C) 2018 by Son J.W*/

using namespace std;

vector<vector<string>> v;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j, n, loc, len;

	cin >> n >> loc;

	v = vector<vector<string>>(n+1);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= 3; j++) {
			if (i == j) {
				v[i].push_back(to_string(j));
			}
			else if (i < j) {
				break;
			}
			else {
				for (string t : v[i - j]) {
					v[i].push_back(t +"+"+ to_string(j));
				}
			}
		}
	}
	len = v[n].size();
	if (loc > len) {
		cout << "-1\n";
	}
	else {
		sort(v[n].begin(), v[n].end());
		cout << v[n][loc - 1] << "\n";
	}
	return 0;
}