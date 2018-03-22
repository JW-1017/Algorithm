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
12
Junkyu 50 60 100
Sangkeun 80 60 50
Sunyoung 80 70 100
Soong 50 60 90
Haebin 50 60 100
Kangsoo 60 80 100
Donghyuk 80 60 100
Sei 70 70 70
Wonseob 70 70 90
Sanghyun 70 70 80
nsj 80 80 80
Taewhan 50 60 90

output
Donghyuk
Sangkeun
Sunyoung
nsj
Wonseob
Sanghyun
Sei
Kangsoo
Haebin
Junkyu
Soong
Taewhan

https://www.acmicpc.net/problem/10825
/* Copyright (C) 2018 by Son */

using namespace std;

class jw {
public:
	string n;
	int a, b, c;
	jw(string n, int a, int b, int c) : n(n), a(a), b(b), c(c) {}

	bool operator<(const jw& t) const { 
		if (this->a > t.a) {
			return 1;
		}
		else if (this->a == t.a) {
			if (this->b < t.b) {
				return 1;
			}
			else if (this->b == t.b) {
				if (this->c > t.c) {
					return 1;
				}
				else if (this->c < t.c) {
					return 0;
				}
				else {
					return this->n < t.n;
				}
			}
			else {
				return 0;
			}
		}
		else {
			return 0;
		}
	}
};
vector<jw> v;
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, a, b, c, i;
	string s;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> s >> a >> b >> c;
		v.push_back(jw(s, a, b, c));
	}
	sort(v.begin(), v.end());
	for (i = 0; i < n; i++) {
		cout << v[i].n << "\n";
	}
	return 0;
}