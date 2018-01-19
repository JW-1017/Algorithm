#include <iostream>
#include <cmath>

/*
input
3
0 3
1 5
45 50

output
3
3
4

https://www.acmicpc.net/problem/1011

/* Copyright (C) 2017 by Son */

using namespace std;

int main() {
	int i, num, plus = 0;
	int dis, sq_dis, m_dis;
	int s_begin, s_end;

	cin >> num;

	/*
	1         1     1
	121       3     4
	12321     5     9
	1234321   7    16

	���� ���� ���� �ִ�� ������ �ְ� �� ���̿� ���ڸ� ������ �ִ�
	*/
	for (i = 0; i < num; i++) {
		cin >> s_begin >> s_end;

		dis = s_end - s_begin;		// ������ ���� ����

		sq_dis = static_cast<int>(floor(sqrt(dis)));		// �߰� �� �� ���� �� �ִ븦 ����
		
		m_dis = dis - static_cast<int>(pow(sq_dis, 2));		// ���� ���̿��� �ִ���̰� �Ǵ� ���̰��� ����
		
		if (m_dis == 0) {
			dis = sq_dis + sq_dis - 1;						// ���̴� �ִ� ���� + �ִ� ���� - 1
		}
		else if (m_dis <= sq_dis) {
			dis = sq_dis + sq_dis;							// ������ �� ���̿� ���� ����
		}
		else {
			while (m_dis >= sq_dis) {						// ���ְ� ū ������ ����
				m_dis = m_dis - sq_dis;
				plus++;
			}
			if (m_dis > 0) {
				plus++;
			}
			dis = sq_dis + sq_dis - 1 + plus;
		}
		plus = 0;
		cout << dis << endl;
	}
	return 0;
}