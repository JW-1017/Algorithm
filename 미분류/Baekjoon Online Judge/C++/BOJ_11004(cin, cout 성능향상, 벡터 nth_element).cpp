#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning(disable:4996)

/* Copyright (C) 2017 by Son */

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);		// cin cout 성능향상
	int i, num, index, val;
	vector<int> v;
	cin >> num >> index;

	for (i = 0; i < num; i++) {
		cin >> val;
		v.push_back(val);
	}
	nth_element(v.begin(), v.begin() + (index-1), v.end());		// 정렬상태에서 n번째 요소 뽑아냄(n번째 요소만 뽑아낼 때 유용)

	cout << v[index - 1] << "\n";		// endl보다 속도빠름
	return 0;
}