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

	길이 차에 따라 최대는 정해져 있고 그 사이에 숫자를 넣은게 최대
	*/
	for (i = 0; i < num; i++) {
		cin >> s_begin >> s_end;

		dis = s_end - s_begin;		// 길이의 차를 구함

		sq_dis = static_cast<int>(floor(sqrt(dis)));		// 중간 값 즉 길이 중 최대를 구함
		
		m_dis = dis - static_cast<int>(pow(sq_dis, 2));		// 원래 길이에서 최대길이가 되는 길이값을 뺀다
		
		if (m_dis == 0) {
			dis = sq_dis + sq_dis - 1;						// 길이는 최대 기점 + 최대 기점 - 1
		}
		else if (m_dis <= sq_dis) {
			dis = sq_dis + sq_dis;							// 작으면 그 사이에 값을 넣음
		}
		else {
			while (m_dis >= sq_dis) {						// 빼주고 큰 값으로 빼줌
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