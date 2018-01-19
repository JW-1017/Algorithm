#include <cstdio>
//#include <functional>
#include <algorithm>

// https://www.acmicpc.net/blog/view/22

using namespace std;

int main() {
	int i, num;
	int* arr;

	scanf("%d", &num);
	arr = new int[num];

	for (i = 0; i < num; i++) { 
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + num);			// ������ġ, ����ġ(vector ���� STL�̳� ��������ǿ����� ��밡��) ��������
	//sort(arr, arr + num, greater<int>());		// ��������
	for (i = 0; i < num; i++) {
		printf("%d\n", arr[i]);
	}
	delete[] arr;
	return 0;
}