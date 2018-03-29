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

// ���ڵ��� �ִ� 4������ �ݺ� �̸� �迭�� � �ݺ��ǳ� ����
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
		if (a == 0) {					// 0�϶� 10���� �̸� ó��
			cout << 10 << endl;
			continue;
		}
		b = b % helper[a]->max;			// max�� Ȯ���Ͽ� �ݺ�Ƚ����ŭ ���� 
		if (b == 0) {					// 0�̸� �缳��
			b = helper[a]->max;
		}
		cout << helper[a]->arr[b - 1] << endl;
	}

	return 0;
}