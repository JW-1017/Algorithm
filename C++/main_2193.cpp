#include <iostream>

/*
input
3
output
2

https://www.acmicpc.net/problem/2193
*/

using namespace std;

int main(void)
{
	int num = 0;
	long long temp = 0;
	cin >> num;

	long long* arr = new long long[3];

	arr[0] = 1;			// 0의 개수
	arr[1] = 1;			// 1의 개수
	arr[2] = 2;			// 총 개수

	if (num == 1 || num == 2) {
		cout << 1 << endl;
		return 0;
	}

	for (int i = 3; i < num; i++) {
		arr[2] = (arr[0] * 2) + arr[1];
		temp = arr[0];
		arr[0] = arr[1] + arr[0];
		arr[1] = temp;
	}

	cout << arr[2] << endl;
	delete[] arr;
	return 0;
}