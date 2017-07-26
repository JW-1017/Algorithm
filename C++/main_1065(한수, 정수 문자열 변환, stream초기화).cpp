#include <iostream>
#include <sstream>
#include <string>

/*
input
110

output
99

https://www.acmicpc.net/problem/1065

/* Copyright (C) 2017 by Son */

using namespace std;

int main() {
	int length, i, j, num;
	int count = 99, value;
	int flag = 2;		// 0 1 2 ������
	string temp;
	stringstream sstream;

	cin >> num;

	if (num < 100) {
		cout << num << endl;
		return 0;
	}
	else if (num >= 100 && num <= 110) {			// 110���� 99��
		cout << 99 << endl;
		return 0;
	}		

	for (i = 111; i <= num; i++) {
		if (flag == 2){								// 2�� �� ���� 8 9�� �ƴϸ� 12�� �����ϸ鼭 �Ѽ� Ȯ�� 
			if ((i % 10) == 8 || (i % 10) == 9) {
				count++;
				i = ((i / 100) + 1) * 100 + 9;		// �ش��ϸ� �״������� �ѱ�
				flag = 1;							
				continue;
			}
			else {
				count++;
				i += 11;
				continue;
			}
		}
		// ���� ���ڿ��� ��ȯ
		sstream << i;
		temp = sstream.str();
		length = temp.length();
		///////////////////////
		flag = 1;
		value = temp[1] - temp[0];					// ���� Ȯ��

		for (j = 2; j < length; j++) {
			if ((temp[j] - temp[j - 1]) != value) {
				sstream.str("");					// stream �ʱ�ȭ
				flag = 0;
				break;
			}
		}
		if (flag) {
			count++;
			flag = 2;
			i += 11;
		}
	}
	cout << count << endl;
	return 0;
}