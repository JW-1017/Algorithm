#include <iostream>
#include <deque>

/*
input
5 3 1
0 -1 0 0 0
-1 -1 0 1 1
0 0 0 1 1

output
-1

https://www.acmicpc.net/problem/7569

/* Copyright (C) 2017 by Son */

using namespace std;

class node {
public:
	int x;
	int y;
	int z;

	node(int x, int y, int z){
		this->x = x;			// dim
		this->y = y;			// col
		this->z = z;			// low
	}
};
int main() {
	std::ios::sync_with_stdio(false);		// cin cout 성능향상
	int i, j, k, low, col, dim, value;
	int total_count = 0;
	int one_count = 0;
	int day = 0;
	int*** arr;
	deque<node> d;
	cin >> low >> col >> dim;
	total_count = low * col * dim;
	arr = new int**[dim];
	for (i = 0; i < dim; i++) {
		arr[i] = new int*[col];
	}
	for (i = 0; i < dim; i++) {
		for (j = 0; j < col; j++) {
			arr[i][j] = new int[low];
			for (k = 0; k < low; k++) {
				cin >> value;
				if (value == -1) {
					total_count--;
				}
				if (value == 1) {
					d.push_back(node(i, j, k));
				}
				arr[i][j][k] = value;
			}
		}
	}
	if (total_count == d.size()) {
		cout << 0 << endl;
		return 0;
	}

	while (1) {
		value = d.size();
		if (value == 0 && total_count != one_count) {
			cout << -1 << endl;
			break;
		}
		if (total_count == (value+one_count)) {
			cout << day << endl;
			break;
		}
		for (i = 0; i < value; i++) {
			node temp = d.back();
			d.pop_back();
			one_count++;
			if (dim != 1) {
				if (temp.x == dim - 1) {
					if (arr[temp.x - 1][temp.y][temp.z] == 0) {
						arr[temp.x - 1][temp.y][temp.z] = 1;
						d.push_front(node(temp.x - 1, temp.y, temp.z));
					}
				}
				else if (temp.x == 0) {
					if (arr[1][temp.y][temp.z] == 0) {
						arr[1][temp.y][temp.z] = 1;
						d.push_front(node(1, temp.y, temp.z));
					}
				}
				else {
					if (arr[temp.x - 1][temp.y][temp.z] == 0) {
						arr[temp.x - 1][temp.y][temp.z] = 1;
						d.push_front(node(temp.x - 1, temp.y, temp.z));
					}
					if (arr[temp.x + 1][temp.y][temp.z] == 0) {
						arr[temp.x + 1][temp.y][temp.z] = 1;
						d.push_front(node(temp.x + 1, temp.y, temp.z));
					}
				}
			}
			if (temp.y == col - 1) {
				if (arr[temp.x][temp.y - 1][temp.z] == 0) {
					arr[temp.x][temp.y - 1][temp.z] = 1;
					d.push_front(node(temp.x, temp.y - 1, temp.z));
				}
			}
			else if (temp.y == 0) {
				if (arr[temp.x][1][temp.z] == 0) {
					arr[temp.x][1][temp.z] = 1;
					d.push_front(node(temp.x, 1, temp.z));
				}
			}
			else {
				if (arr[temp.x][temp.y - 1][temp.z] == 0) {
					arr[temp.x][temp.y - 1][temp.z] = 1;
					d.push_front(node(temp.x, temp.y - 1, temp.z));
				}
				if (arr[temp.x][temp.y + 1][temp.z] == 0) {
					arr[temp.x][temp.y + 1][temp.z] = 1;
					d.push_front(node(temp.x, temp.y + 1, temp.z));
				}
			}
			if (temp.z == low - 1) {
				if (arr[temp.x][temp.y][temp.z - 1] == 0) {
					arr[temp.x][temp.y][temp.z - 1] = 1;
					d.push_front(node(temp.x, temp.y, temp.z - 1));
				}
			}
			else if (temp.z == 0) {
				if (arr[temp.x][temp.y][1] == 0) {
					arr[temp.x][temp.y][1] = 1;
					d.push_front(node(temp.x, temp.y, 1));
				}
			}
			else {
				if (arr[temp.x][temp.y][temp.z - 1] == 0) {
					arr[temp.x][temp.y][temp.z - 1] = 1;
					d.push_front(node(temp.x, temp.y, temp.z - 1));
				}
				if (arr[temp.x][temp.y][temp.z + 1] == 0) {
					arr[temp.x][temp.y][temp.z + 1] = 1;
					d.push_front(node(temp.x, temp.y, temp.z + 1));
				}
			}
		}
		day++;
	}
	for (i = 0; i < dim; i++) {
		for (j = 0; j < col; j++) {
			delete[] arr[i][j];
		}
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}