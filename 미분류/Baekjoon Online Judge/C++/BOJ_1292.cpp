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

	// i�� ������ ���� i���� ���� �� (3�� 2���� ���� �� 3���� 4���� 3���� ���� �� 6���� ����)
	for (i = 1; i < 1000; i++) {
		sum += i;

		if (a_end <= sum && check == 1) {
			result += i * (a_end - (sum - i));
			break;
		}

		// ������ i���� ���� ������ ������
		if (a_begin <= sum && check == 0) {				
			// ���� ���� �� ���� Ŭ ��
			if (a_end > sum) {
				result += i * (sum - a_begin + 1);
				check = 1;	// check�� ��ȭ�� end�� ���� ��� ���ϱ⸸
			}
			// �۰ų� ���� ���� ���� �� �� ����(5, 6 �̸� �� �� 3)
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