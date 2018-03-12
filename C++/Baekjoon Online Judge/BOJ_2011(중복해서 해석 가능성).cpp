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
25114

output
6

https://www.acmicpc.net/problem/2011
/* Copyright (C) 2018 by Son */

#define mod 1000000

using namespace std;

int arr[5001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j, t, len;
	string str;
	cin >> str;
	len = str.length();
	if (str[0] == '0') {
		cout << "0\n";
		return 0;
	}
	arr[0] = 1;			// 인덱스 -2를 사용하므로 인덱스 1에서의 활용을 위해
	arr[1] = 1;
	for (i = 1; i < len; i++) {
		t = i + 1;		// memo하는 arr에서 저장하는 곳은 인덱스 +1
		if (str[i] == '0') {		// 0이라면 두번째 앞에 있는 곳과 동일
			arr[t] = arr[t - 2];
			continue;
		}
		// 10 에서 26사이인지 확인, 10은 이미 위에 if문에서 걸러짐
		j = (str[i - 1] - '0') * 10 + str[i] - '0';
		if (j > 10 && j < 27) {
			// 두번앞에까지의 결과와 바로앞 결과의 합
			// 2 5 14, 2 5 1 4, 25 14, 25 1 4 합침으로써 두번째 앞까지의 경우수 +
			arr[t] = (arr[t - 2] + arr[t - 1]) % mod;
		}
		else {
			// 아니라면 그대로 받음
			arr[t] = arr[t - 1];
		}
	}
	cout << arr[len] << "\n";
	return 0;
}