#include <iostream>
#include <queue>
/*
input
3
1 0
5
4 2
1 2 3 4
6 0
1 1 9 1 1 1

output
1
2
5

https://www.acmicpc.net/problem/1966
*/
using namespace std;

class printer {
public:
	int value;
	bool index;
	printer(int value) {
		index = false;
		this->value = value;
	}
	printer(int value, bool index) {
		this->index = true;
		this->value = value;
	}
};

void clear(queue<printer*> &q);
void sort_swap(int arr[], int i, int j);
void quickSort(int arr[], int firstarr, int lastarr);

int main() {
	int i, j, num, len, count;
	int* arr;
	cin >> num;

	queue<printer*> que;

	for (i = 0; i < num; i++) {
		cin >> len >> count;
		
		clear(que);
		arr = new int[len];

		for (j = 0; j < len; j++) {
			cin >> arr[j];

			if (j == count) {
				que.push(new printer(arr[j], true));			// 해당 번쨰 숫자만 true로 저장
				continue;
			}
			que.push(new printer(arr[j]));
		}
		quickSort(arr, 0, len - 1);								// 배열을 오름차순으로 정렬

		for (j = 0; j < len; j++) {
			while (1) {
				if (que.front()->value == arr[j]) {
					break;
				}
				que.push(que.front());
				que.pop();
			}
			if (que.front()->index) {
				break;
			}
			que.pop();
		}
		cout << j+1 << endl;
		delete[] arr;
	}
	return 0;
}

void clear(queue<printer*> &q) {
	queue<printer*> empty;
	swap(q, empty);
}

void sort_swap(int arr[], int i, int j) {
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void quickSort(int arr[], int firstarr, int lastarr) {
	int leftward, rightward;
	int pivot;

	if (lastarr > firstarr) {
		pivot = arr[lastarr];
		leftward = firstarr - 1;
		rightward = lastarr;

		while (leftward < rightward) {
			do {
				if (leftward == lastarr) {
					break;
				}
				leftward++;
			} while (arr[leftward] > pivot);
			do {
				if (rightward == firstarr) {
					break;
				}
				rightward--;
			} while (arr[rightward] < pivot);
			if (leftward < rightward) {
				sort_swap(arr, leftward, rightward);
			}
		}
		sort_swap(arr, leftward, lastarr);
		quickSort(arr, firstarr, leftward - 1);
		quickSort(arr, leftward + 1, lastarr);
	}
}