#include <iostream>

using namespace std;

int main(void)
{
	int i, num, temp, count;

	cin >> num;

	int* arr = new int[num];
	// c++ ������ �迭 �����Ҵ�   2�� num��
	int** max = new int*[2];			

	for (i = 0; i < 2; i++) {
		max[i] = new int[num];
	}
	////////////////////////
	delete[] arr;
	// c++ ������ �迭 �����Ҵ� ����
	for (i = 0; i < 2; i++) {
		delete[] max[i];
	}
	delete[] max;
	/////////////////////////////
	return 0;
}