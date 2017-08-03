#include <iostream>

/*
input
2
6 12 10
30 50 72

output
402
1203

https://www.acmicpc.net/problem/10250

/* Copyright (C) 2017 by Son */

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);		// cin cout 성능향상
	int i, num, h, w, s_count;
	int f_count, floor;

	cin >> num;

	for (i = 0; i < num; i++) {
		cin >> h >> w >> s_count;
		if (s_count % h == 0) {			// 나누어 떨어질 때 꼭 염두(6 12 6번째일 때)
			floor = (s_count / h);
			f_count = h;
		}
		else {
			floor = (s_count / h) + 1;
			f_count = s_count - (h * (floor - 1));
		}

		cout << f_count * 100 + floor << '\n';
	}
	return 0;
}