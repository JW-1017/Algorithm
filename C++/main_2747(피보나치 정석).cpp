#include <iostream>

using namespace std;
/*
input
17

output
1597

https://www.acmicpc.net/problem/2747

/* Copyright (C) 2017 by Son */
int main() {
	int i, num;
	long long prev, curr, next;
	long long result = 0;

	cin >> num;

	if (num == 1) {
		result = 1;
	}
	else {
		prev = 0;
		curr = 1;
		for (i = 2; i <= num; i++) {
			next = prev + curr;
			prev = curr;
			curr = next;
		}
		result = next;
	}
	cout << result << endl;
}