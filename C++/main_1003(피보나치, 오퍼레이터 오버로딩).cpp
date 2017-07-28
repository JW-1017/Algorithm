#include <iostream>

/*
input
3
0
1
3

output
1 0
0 1
1 2

https://www.acmicpc.net/problem/1003

/* Copyright (C) 2017 by Son */

using namespace std;

class fibo_num {
public:
	int zero_count;
	int one_count;
	bool exit;						// 이미 계산된 값인지 확인(test case가 여러개여서)
	fibo_num() {
		this->zero_count = 0;
		this->one_count = 0;
		this->exit = 0;
	}
	fibo_num(int zero, int one) {
		this->zero_count = zero;
		this->one_count = one;
		this->exit = 1;
	}
	fibo_num& operator=(const fibo_num& temp) {
		if (this != &temp) {
			this->zero_count = temp.zero_count;
			this->one_count = temp.one_count;
		}
		return *this;
	}
};

fibo_num operator+(const fibo_num& f1, const fibo_num& f2) {
	return fibo_num(f1.zero_count + f2.zero_count, f1.one_count + f2.one_count);
}
fibo_num f_arr[41];

int main() {
	int i = 0, j = 2, num;
	int value;

	cin >> num;
	f_arr[0].zero_count = 1;
	f_arr[0].exit = 1;

	f_arr[1].one_count = 1;
	f_arr[1].exit = 1;

	for (; i < num; i++) {
		cin >> value;

		for ( ; j <= value; j++) {						// 현재는 이전과 그 이전의 0, 1 개수의 합
			f_arr[j] = f_arr[j - 1] + f_arr[j - 2];
		}
		
		cout << f_arr[value].zero_count << " " << f_arr[value].one_count << endl;
	}
	return 0;
}