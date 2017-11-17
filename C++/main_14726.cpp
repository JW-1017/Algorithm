#include <iostream>
#include <algorithm>
#include <string>

/*
input
3
2720992711828767
3444063910462763
6011733895106094

output
T
F
T

https://www.acmicpc.net/problem/14726
/* Copyright (C) 2017 by Son */

using namespace std;

int main() {
	int i, j, num;
	int temp, sum;
	string str;
	std::ios::sync_with_stdio(false);		// cin cout 성능향상

	cin >> num;

	for (i = 0; i < num; i++) {
		sum = 0;
		cin >> str;
		reverse(str.begin(), str.end());
		for (j = 0; j < 16; j++) {
			if (j % 2 == 1) {
				temp = str[j] - '0';
				temp *= 2;
				if (temp >= 10) {
					temp = temp - 10 + 1;
				}
				str[j] = temp + '0';
			}
			sum += str[j] - '0';
		}
		if (sum % 10 == 0) {
			cout << "T\n";
		}
		else {
			cout << "F\n";
		}
	}
	return 0;
}