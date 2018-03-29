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
4 3
1 1 2 0
2 0 1 0
3 0 1 0
4 0 0 1

output
2

https://www.acmicpc.net/problem/8979
/* Copyright (C) 2018 by Son */

using namespace std;

class medal {
public:
	int num;
	int me[3];
	medal() {}
	medal(int num, int a, int b, int c) {
		this->num = num;
		this->me[0] = a;
		this->me[1] = b;
		this->me[2] = c;
	}
	void init(int num, int a, int b, int c) {
		this->num = num;
		this->me[0] = a;
		this->me[1] = b;
		this->me[2] = c;
	}
	// const!!
	bool operator <(const medal& m) {
		if (this->me[0] == m.me[0]) {
			if (this->me[1] == m.me[1]) {
				if (this->me[2] == m.me[2]) {
					return 0;
				}
				else {
					return this->me[2] < m.me[2];
				}
			}
			else {
				return this->me[1] < m.me[1];
			}
		}
		else {
			return this->me[0] < m.me[0];
		}
	}
	bool operator >(const medal& m) {
		if (this->me[0] == m.me[0]) {
			if (this->me[1] == m.me[1]) {
				if (this->me[2] == m.me[2]) {
					return 0;
				}
				else {
					return this->me[2] > m.me[2];
				}
			}
			else {
				return this->me[1] > m.me[1];
			}
		}
		else {
			return this->me[0] > m.me[0];
		}
	}
	bool operator ==(const medal& m) {
		if (this->me[0] == m.me[0]) {
			if (this->me[1] == m.me[1]) {
				if (this->me[2] == m.me[2]) {
					return 1;
				}
			}
		}
		return 0;
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, n, k, s, a, b, c;
	vector<medal> d;
	vector<medal>::iterator it;
	cin >> n >> k;
	medal te1, te2;
	for (i = 0; i < n; i++) {
		cin >> s >> a >> b >> c;
		if (s == k) {
			// 원하는 등수만 따로 빼냄
			te1 = medal(s, a, b, c);
		}
		else {
			// 나머지는 벡터에 추가할지 개수 증가할지
			te2 = medal(1, a, b, c);
			if ((it = find(d.begin(), d.end(), te2)) != d.end()) {
				it->num++;
			}
			else {
				d.push_back(te2);
			}
		}
	}
	// 오름차순 정렬
	sort(d.begin(), d.end());
	n = d.size(); a = 1;
	// 뒤부터 오면서 큰수 결정
	for (i = n-1; i >= 0; i--) {
		if (d[i] > te1) {
			a += d[i].num;
		}
		else {
			break;
		}
	}
	cout << a << "\n";
	return 0;
}