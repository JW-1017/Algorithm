#include <iostream>
#include <string>

/*
input
7 12

output
THU

https://www.acmicpc.net/problem/1924

/* Copyright (C) 2017 by Son */

using namespace std;

int main() {
	int total_day = 0;
	int i, month, day;
	string week[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

	cin >> month >> day;

	for (i = 1; i < month; i++) {
		if (i == 2) {
			total_day += 28;
		}
		else if (i == 4 || i == 6 || i == 9 || i == 11) {
			total_day += 30;
		}
		else {
			total_day += 31;
		}
	}
	total_day += day;

	cout << week[(total_day - 1) % 7] << endl;
	return 0;
}