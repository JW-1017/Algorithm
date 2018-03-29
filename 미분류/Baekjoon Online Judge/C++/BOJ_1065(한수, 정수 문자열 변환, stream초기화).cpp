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
	int flag = 2;		// 0 1 2 세가지
	string temp;
	stringstream sstream;

	cin >> num;

	if (num < 100) {
		cout << num << endl;
		return 0;
	}
	else if (num >= 100 && num <= 110) {			// 110까지 99임
		cout << 99 << endl;
		return 0;
	}		

	for (i = 111; i <= num; i++) {
		if (flag == 2){								// 2일 때 끝이 8 9가 아니면 12씩 증가하면서 한수 확인 
			if ((i % 10) == 8 || (i % 10) == 9) {
				count++;
				i = ((i / 100) + 1) * 100 + 9;		// 해당하면 그다음으로 넘김
				flag = 1;							
				continue;
			}
			else {
				count++;
				i += 11;
				continue;
			}
		}
		// 숫자 문자열로 변환
		sstream << i;
		temp = sstream.str();
		length = temp.length();
		///////////////////////
		flag = 1;
		value = temp[1] - temp[0];					// 차이 확인

		for (j = 2; j < length; j++) {
			if ((temp[j] - temp[j - 1]) != value) {
				sstream.str("");					// stream 초기화
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