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

	arr[0] = new int[num];				// ���� �� ����
	arr[1] = new int[num];				// �̾����� �ִ� �� ����

	getchar();
	getline(cin, str);
	stringstream stream(str);

	while (stream >> temp) {
		value = stoi(temp);
		arr[0][i] = value;

		if (i == 0) {				// 0��° �� �� �ʱ�ȭ
			result = value;			// �ִ밪 ����
			arr[1][0] = value;
			i++;
			continue;
		}

		arr[1][i] = max(arr[1][i - 1] + value, value);		// �̾����� ���� �� ���� ������ 
		result = max(arr[1][i], result);					// �ִ밪 ����

		i++;
	}
	cout << result << endl;
	for (i = 0; i < 2; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}