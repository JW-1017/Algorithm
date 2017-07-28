#include <cstdio>
#include <cmath>
/*
output
1
3
5
7
9
20
31
42
53
64
|
|       <-- a lot more numbers
|
9903
9914
9925
9927
9938
9949
9960
9971
9982
9993

https://www.acmicpc.net/problem/4673

/* Copyright (C) 2017 by Son */

using namespace std;

bool arr[10000] = { 0 };

void self_number(int num) {
	if (num >= 10000) {
		return;
	}
	int len = static_cast<int>(log10(num)) + 1;			// 자릿수 구하기
	int temp = num;
	int share;
	for (int j = len; j > 0; j--) {						// 자릿수 다 더하기
		int pow_num = static_cast<int>(pow(10, j-1));
		share = num / pow_num;
		temp += share;
		num -= share * pow_num;
	}
	if (arr[temp - 1] == 1) {							// 이미 바꿔있으면 리턴
		return;
	}
	arr[temp - 1] = 1;						// 1이면 셀프넘버가 아님(더해서 만들어짐)
	self_number(temp);
}

int main() {
	int i = 1;
	for ( ; i <= 10000; i++) {
		self_number(i);
	}
	for (i = 0; i < 10000; i++) {
		if (arr[i] == 0) {
			printf("%d\n", i+1);
		}
	}
	return 0;
}