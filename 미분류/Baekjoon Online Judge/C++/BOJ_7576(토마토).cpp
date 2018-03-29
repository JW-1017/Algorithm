#include <iostream>
#include <deque>
/*
input
6 4
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 1

output
8

https://www.acmicpc.net/problem/7576

/* Copyright (C) 2017 by Son */

using namespace std;

class node {
public:
	int x;
	int y;
	node(int x, int y){
		this->x = x;
		this->y = y;
	}
};

int main() {
	std::ios::sync_with_stdio(false);		// cin cout 성능향상
	int i, j, low, col, value;
	int total_count = 0;
	int one_count = 0;
	int day = 0;
	int** arr;
	deque<node> d;
	cin >> low >> col;
	total_count = low*col;
	arr = new int*[col];
	for (i = 0; i < col; i++) {
		arr[i] = new int[low];
		for (j = 0; j < low; j++) {
			cin >> value;
			if (value == -1) {
				total_count--;
			}
			else if (value == 1) {
				d.push_back(node(i, j));
			}
			arr[i][j] = value;
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

			if (temp.x == col - 1) {
				if (arr[temp.x - 1][temp.y] == 0 ) {
					arr[temp.x - 1][temp.y] = 1;
					d.push_front(node(temp.x - 1, temp.y));
				}
			}
			else if (temp.x == 0) {
				if (arr[1][temp.y] == 0) {
					arr[1][temp.y] = 1;
					d.push_front(node(1, temp.y));
				}
			}
			else {
				if (arr[temp.x - 1][temp.y] == 0) {
					arr[temp.x - 1][temp.y] = 1;
					d.push_front(node(temp.x - 1, temp.y));
				}
				if (arr[temp.x + 1][temp.y] == 0) {
					arr[temp.x + 1][temp.y] = 1;
					d.push_front(node(temp.x + 1, temp.y));
				}
			}
			if (temp.y == low - 1) {
				if (arr[temp.x][temp.y - 1] == 0) {
					arr[temp.x][temp.y - 1] = 1;
					d.push_front(node(temp.x, temp.y - 1));
				}
			}
			else if (temp.y == 0) {
				if (arr[temp.x][1] == 0) {
					arr[temp.x][1] = 1;
					d.push_front(node(temp.x, 1));
				}
			}
			else {
				if (arr[temp.x][temp.y - 1] == 0) {
					arr[temp.x][temp.y - 1] = 1;
					d.push_front(node(temp.x, temp.y - 1));
				}
				if (arr[temp.x][temp.y + 1] == 0) {
					arr[temp.x][temp.y + 1] = 1;
					d.push_front(node(temp.x, temp.y + 1));
				}
			}
		}
		day++;
	}
	for (i = 0; i < col; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}