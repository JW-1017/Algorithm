#include <iostream>

using namespace std;
/*
input 
10 11 12

output
4

https://www.acmicpc.net/problem/1629

/* Copyright (C) 2017 by Son */
int main() {
	long long val = 1;
	long long num, exponent, mod;		// num : 곱하는 수, exponent : 곱하는 횟수, mod : 나누는 수(나중에 안쓰임) pow(num, exponent)를 log(n)으로
	cin >> num >> exponent >> mod;
	
	// 지수를 2진수로 변환하여 곱 https://xlinux.nist.gov/dads/HTML/repeatedSquaring.html 
	while (exponent > 0) {
		if (exponent % 2 == 1) {		
			val = (val * num) % mod;
		}
		exponent /= 2;
		num = (num * num) % mod;
	}
	cout << val << endl;
	return 0;
}