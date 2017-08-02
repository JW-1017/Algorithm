#include <iostream>

using namespace std;

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
	delete[] arr;
	// c++ 이차원 배열 동적할당 해제
	for (i = 0; i < 2; i++) {
		delete[] max[i];
	}
	delete[] max;
	/////////////////////////////
	return 0;
}