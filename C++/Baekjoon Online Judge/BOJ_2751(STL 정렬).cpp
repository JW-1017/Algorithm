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
	sort(arr, arr + num);			// 시작위치, 끝위치(vector 등의 STL이나 사용자정의에서도 사용가능) 오름차순
	//sort(arr, arr + num, greater<int>());		// 내림차순
	for (i = 0; i < num; i++) {
		printf("%d\n", arr[i]);
	}
	delete[] arr;
	return 0;
}