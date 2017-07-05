#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

/*
input
10
10 -4 3 1 5 6 -35 12 21 -1

10
10 -4 3 1 5 6 -35 12 1 -1

11
3 9 -8 6 4 -7 5 -4 4 -2 5

11
3 9 -8 6 4 -7 5 -4 20 -9 5

output
33
21
15
28

https://www.acmicpc.net/problem/1912
*/
using namespace std;

int main() {
	int i = 0, value, num, result; 
	string temp;
	string str;
	int** arr = new int*[2];

	cin >> num;

	arr[0] = new int[num];				// 현재 값 저장
	arr[1] = new int[num];				// 이어지는 최대 값 저장

	getchar();
	getline(cin, str);
	stringstream stream(str);

	while (stream >> temp) {
		value = stoi(temp);
		arr[0][i] = value;

		if (i == 0) {				// 0번째 일 때 초기화
			result = value;			// 최대값 저장
			arr[1][0] = value;
			i++;
			continue;
		}

		arr[1][i] = max(arr[1][i - 1] + value, value);		// 이어지는 값일 지 나의 값일지 
		result = max(arr[1][i], result);					// 최대값 갱신

		i++;
	}
	cout << result << endl;
	for (i = 0; i < 2; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}