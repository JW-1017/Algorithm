#include <iostream>
#include <cmath>

/*
input
5
1 6
3 7
6 2
7 100
9 635

output
1
7
6
1
9

https://www.acmicpc.net/problem/1009

/* Copyright (C) 2017 by Son */

using namespace std;

class num_recur {
public:
	int max;
	int arr[4];
};

// 숫자들은 최대 4개까지 반복 미리 배열과 몇개 반복되나 설정
void make_recur(num_recur* temp ,int num) {			 
	temp->arr[0] = num;
	for (int i = 1; i < 4; i++) {
		temp->arr[i] = (int)pow(num, i + 1) % 10;
		if (temp->arr[0] == temp->arr[i]) {
			temp->max = i;
			return;
		}
	}
	temp->max = 4;
}

int main(void)
{
	int i, a, b, num;	
	cin >> num;

	num_recur* helper[10];

	for (i = 0; i < 10; i++) {
		helper[i] = new num_recur();
		make_recur(helper[i], i);
	}

	for (i = 0; i < num; i++) {
		cin >> a >> b;
		a = a % 10;
		if (a == 0) {					// 0일때 10으로 미리 처리
			cout << 10 << endl;
			continue;
		}
		b = b % helper[a]->max;			// max값 확인하여 반복횟수만큼 나눔 
		if (b == 0) {					// 0이면 재설정
			b = helper[a]->max;
		}
		cout << helper[a]->arr[b - 1] << endl;
	}

	return 0;
}