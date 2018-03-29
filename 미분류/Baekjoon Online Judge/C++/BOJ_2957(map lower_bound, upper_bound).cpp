#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>

/*
input
8
3
5
1
6
8
7
2
4

output
0
1
2
4
7
11
13
15

https://www.acmicpc.net/problem/2957

/* Copyright (C) 2017 by Son */

using namespace std;

int main() {
	int i, num;
	int value;
	long long i_count = 0;
	stringstream result;
	map<int, int> m;
	
	scanf("%d",&num);

	m[0] = -1;
	m[300001] = -1;

	scanf("%d", &value);
	m[value] = 0;

	result << "0" << endl;

	for (i = 1; i < num; i++) {
		scanf("%d", &value);

		//	upperbound는 키 값보다 큰 값, lowerbound는 키 값보다 작지 않은 값(자신 포함)
		m[value] = max((--m.lower_bound(value))->second, m.upper_bound(value)->second) + 1;				

		i_count += m[value];

		result << i_count << endl;
	}
	cout << result.str();
	return 0;
}