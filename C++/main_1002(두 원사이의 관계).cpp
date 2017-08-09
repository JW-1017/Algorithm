#include <iostream>
#include <cmath>
#include <algorithm>
/*
input
3
0 0 13 40 0 37
0 0 3 0 7 4
1 1 1 1 1 5

output
2
1
0

https://www.acmicpc.net/problem/1002

/* Copyright (C) 2017 by Son */

using namespace std;

double get_dis(int x1, int y1, int x2, int y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
	std::ios::sync_with_stdio(false);		// cin cout �������
	int i, num;
	int x1, y1, x2, y2;
	double r1, r2, r3, r4, r5;
	
	cin >> num;

	for (i = 0; i < num; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		if (x1 == x2 && y1 == y2) {		// ��ġ�� ���� ��
			if (r1 == r2) {
				cout << -1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else {
			r3 = get_dis(x1, y1, x2, y2);

			if (r1 + r2 > r3) {						
				r4 = max(r1, r2);
				r5 = min(r1, r2);

				if (r4 - r5 == r3) {				// ����
					cout << 1 << endl;
				}
				else if (r4 - r5 > r3){				// ���ʿ��� �� ����
					cout << 0 << endl;
				}
				else {								// �������� ����
					cout << 2 << endl;
				}
			}
			else if (r1 + r2 == r3) {				// ����
				cout << 1 << endl;
			}
			else {									// �ٱ��ʿ��� �� ����
				cout << 0 << endl;
			}
		}
	}
	return 0;
}