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
7

output
1213121

https://www.acmicpc.net/problem/2661
/* Copyright (C) 2018 by Son */

using namespace std;

string str = "12";
int n;

bool solve(int l) {
	int num = 2;
	string temp = "", temp2 = "";
	temp += str[l - 1];
	temp2 += str[l - 2];
	// 끝에만 붙여가면서 확인 (그 전까지는 확실하니까)
	while (1) {
		if (temp == temp2) {
			return 0;
		}
		// 해당 길이를 넘어설 때 (앞에 num수와 비교 하기 전 index가 넘어서버리면)
		if (l - num - num < 0) {
			break;
		}
		// 바로앞 character 붙이기
		temp = str[l-num] + temp;
		temp2 = "";
		// 절반 이전 문자열
		for (int s = 0; s < num; s++) {
			temp2 += str[l - num - s - 1];
		}
		// 뒤집기
		reverse(temp2.begin(), temp2.end());
		num++;
	}
	if (l == n) {
		return 1;
	}
	for (char i = '1'; i <= '3'; i++) {
		str += i;
		// 붙여보고
		if (solve(l + 1)) {
			return 1;
		}
		// 떼고
		str = str.substr(0, l);
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	if (n == 1) {
		cout << "1\n";
		return 0;
	}
	solve(2);
	cout << str << "\n";

	return 0;
}