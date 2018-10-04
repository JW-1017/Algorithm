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
#include <sstream>

using namespace std;

/*
input:

output:
2992
2993
2994
2995
2996
2997
2998
2999

https://www.acmicpc.net/problem/6679
/* Copyright (C) 2018 by Son J.W*/

typedef pair<int, int> pa;
typedef vector<int> vi;
typedef vector<vi> vvi;

// 진법 자리수 합 반환 num은 변환할 10진법수, to 는 몇 진법인지
int to_notation(int num, int to) {
	// 진법수 반환
	//string s = "";

	int temp = 0;

	while (num > 0) {
		temp += (num % to);
		// 진법수 생성
		// s = to_string(num % to) + s;
		num /= to;
	}
	return temp;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i;

	for (i = 1000; i <= 9999; i++) {
		if ((to_notation(i, 10) == to_notation(i, 12)) && (to_notation(i, 12) == to_notation(i, 16))) {
			cout << i << "\n";
		}
	}
	return 0;
}