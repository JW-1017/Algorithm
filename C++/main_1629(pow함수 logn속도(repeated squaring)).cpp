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
	long long num, exponent, mod;		// num : ���ϴ� ��, exponent : ���ϴ� Ƚ��, mod : ������ ��(���߿� �Ⱦ���) pow(num, exponent)�� log(n)����
	cin >> num >> exponent >> mod;
	
	// ������ 2������ ��ȯ�Ͽ� �� https://xlinux.nist.gov/dads/HTML/repeatedSquaring.html 
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