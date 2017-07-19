#include <iostream>

/*
input 
6
6
10
13
9
8
1
output
33
https://www.acmicpc.net/problem/2156
*/

using namespace std;

int find_max(int arr[], int index, int value, int sel, int& count);

int main(void)
{
	int i, num, temp, count;

	cin >> num;

	int* arr = new int[num];
	// c++ 이차원 배열 동적할당   2행 num열
	int** max = new int*[2];			

	for (i = 0; i < 2; i++) {
		max[i] = new int[num];
	}
	////////////////////////
	for (i = 0; i < num; i++) {
		cin >> arr[i];
	}

	max[0][0] = arr[0];
	max[1][0] = 1;

	max[0][1] = arr[0] + arr[1];
	max[1][1] = 2;

	max[0][2] = find_max(arr, 2, 0, 0, count);
	max[1][2] = count;

	// 앞에서 3번째의 상태 확인 후 최댓값 결정, 2번째 상태확인 후 최댓값 결정, 바로앞 상태확인후 최댓값 결정 
	for (i = 3; i < num; i++) {							
		if (max[1][i - 3] == 0) {
			max[0][i] = find_max(arr, i, max[0][i - 3], 0, count);
			max[1][i] = count;
		}
		else if (max[1][i - 3] == 1) {
			max[0][i] = find_max(arr, i, max[0][i - 3], 1, count);
			max[1][i] = count;
		}
		else {
			max[0][i] = max[0][i - 3] + arr[i - 1] + arr[i];
			max[1][i] = 2;
		}
		if (max[1][i - 2] == 0) {
			temp = max[0][i - 2] + arr[i - 1] + arr[i];
			if (max[0][i] < temp) {
				max[0][i] = temp;
				max[1][i] = 2;
			}
		}
		else if (max[1][i - 2] == 1) {
			if (arr[i - 1] > arr[i]) {
				temp = arr[i - 1] + max[0][i - 2];
				count = 0;
			}
			else {
				temp = arr[i] + max[0][i - 2];
				count = 1;
			}
			if (temp > max[0][i]) {
				max[0][i] = temp;
				max[1][i] = count;
			}
		}
		else {
			temp = max[0][i - 2] + arr[i];
			if (max[0][i] < temp) {
				max[0][i] = temp;
				max[1][i] = 1;
			}
		}
		if (max[1][i - 1] == 0) {
			temp = max[0][i - 1] + arr[i];
			if (max[0][i] < temp) {
				max[0][i] = temp;
				max[1][i] = 1;
			}
		}
		else if (max[1][i - 1] == 1) {
			temp = max[0][i - 1] + arr[i];
			if (max[0][i] < temp) {
				max[0][i] = temp;
				max[1][i] = 2;
			}
		}
		else {
			temp = max[0][i - 1];
			if (max[0][i] < temp) {
				max[0][i] = temp;
				max[1][i] = 0;
			}
		}
	}
	cout << max[0][num - 1] << endl;
	delete[] arr;
	// c++ 이차원 배열 동적할당 해제
	for (i = 0; i < 2; i++) {
		delete[] max[i];
	}
	delete[] max;
	/////////////////////////////
	return 0;
}
int find_max(int arr[], int index, int value, int sel, int& count) {
	int* temp = new int[2];
	count = -1;

	int max = 0;
	if (sel == 0) {
		max = value + arr[index - 2] + arr[index - 1];
		temp[0] = value + arr[index - 2] + arr[index];
		temp[1] = value + arr[index - 1] + arr[index];
	}
	else if (sel == 1) {
		max = value + arr[index - 2] + arr[index];
		temp[0] = value + arr[index - 1] + arr[index];

		if (max > temp[0]) {
			count = 1;
		}
		else {
			max = temp[0];
			count = 2;
		}
		return max;
	}
	for (int i = 0; i < 2; i++) {
		if (max < temp[i]) {
			max = temp[i];
			count = i;
		}
	}
	count += 1;
	return max;
}