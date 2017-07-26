#include <iostream>
#include <string>
#include <map>
#include <vector>

/*
input
13
but
i
wont
hesitate
no
more
no
more
it
cannot
wait
im
yours

output
i
im
it
no
but
more
wait
wont
yours
cannot
hesitate

https://www.acmicpc.net/problem/1181

/* Copyright (C) 2017 by Son */

using namespace std;

void sort_swap(vector<string>& arr, int i, int j);
void quickSort(vector<string>& arr, int firstarr, int lastarr);

int main() {
	int i, num;
	unsigned int j;
	int length;

	cin >> num;

	string temp;
	map<int, vector<string>> m;
	map<int, vector<string>>::iterator m_iter;

	for (i = 0; i < num; i++) {
		cin >> temp;
		length = temp.length();

		m[length].push_back(temp);
	}
	
	m_iter = m.begin();

	for (; m_iter != m.end(); m_iter++) {
		quickSort(m_iter->second, 0, m_iter->second.size()-1);
	}

	for (m_iter = m.begin(); m_iter != m.end(); m_iter++) {
		for (j = 0; j < m_iter->second.size(); j++) {
			if (j > 0 && m_iter->second[j - 1] == m_iter->second[j]) {
				continue;
			}
			cout << m_iter->second[j] << endl;
		}
	}
	return 0;
}

void sort_swap(vector<string>& arr, int i, int j) {
	string temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void quickSort(vector<string>& arr, int firstarr, int lastarr) {
	int leftward, rightward;
	string pivot;

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
			} while (arr[leftward] < pivot);
			do {
				if (rightward == firstarr) {
					break;
				}
				rightward--;
			} while (arr[rightward] > pivot);
			if (leftward < rightward) {
				sort_swap(arr, leftward, rightward);
			}
		}
		sort_swap(arr, leftward, lastarr);
		quickSort(arr, firstarr, leftward - 1);
		quickSort(arr, leftward + 1, lastarr);
	}
}