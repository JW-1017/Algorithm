#include <iostream>

/*
input
3 7

output
15

https://www.acmicpc.net/problem/1292

/* Copyright (C) 2017 by Son */

using namespace std;

int main() {
	int i, a_begin, a_end;
	int check = 0, sum = 0;
	long long result = 0;

	cin >> a_begin >> a_end;

	// i의 숫자의 끝이 i까지 더한 값 (3은 2까지 더한 값 3이후 4부터 3까지 더한 값 6까지 존재)
	for (i = 1; i < 1000; i++) {
		sum += i;

		if (a_end <= sum && check == 1) {
			result += i * (a_end - (sum - i));
			break;
		}

		// 시작이 i까지 더한 값보다 작으면
		if (a_begin <= sum && check == 0) {				
			// 끝이 더한 값 보다 클 때
			if (a_end > sum) {
				result += i * (sum - a_begin + 1);
				check = 1;	// check값 변화로 end전 까지 계속 더하기만
			}
			// 작거나 같을 때가 존재 할 수 있음(5, 6 이면 둘 다 3)
			else {
				result = i * (a_end - a_begin + 1);
				break;
			}
		}
		else if (check == 1) {
			result += i * i;
		}
	}
	cout << result << endl;
	return 0;
}