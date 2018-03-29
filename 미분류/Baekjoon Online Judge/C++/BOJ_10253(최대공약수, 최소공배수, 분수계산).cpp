#include <iostream>
#include <cmath>

using namespace std;

/*
input:
3
4 23
5 7
8 11

output:
138
70
4070

https://www.acmicpc.net/problem/10253
/* Copyright (C) 2017 by Son */

int gcd(int a, int b)		// 최대공약수
{
	int temp;
	while (b != 0) {
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int num;
	cin >> num;
	int i, ja, mo, div, lcm, div1, div2, mo_gcd;

	for (i = 0; i < num; i++) {
		cin >> ja >> mo;
		div = mo;
		while (ja) {
			div = (mo-1) / ja + 1;			// 가장 근접한 수 찾기
			/*
			mo_gcd = gcd(mo, div);

			lcm = (mo * div) / mo_gcd;		// 최소공배수
			div1 = lcm / mo;
			div2 = lcm / div;

			ja = (ja * div1) - div2;
			mo = lcm;
			*/
			ja = ja*div - mo;
			mo = mo * div;
		}
		cout << div << "\n";
	}
	return 0;
}