#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning(disable:4996)

/* Copyright (C) 2017 by Son */

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);		// cin cout �������
	int i, num, index, val;
	vector<int> v;
	cin >> num >> index;

	for (i = 0; i < num; i++) {
		cin >> val;
		v.push_back(val);
	}
	nth_element(v.begin(), v.begin() + (index-1), v.end());		// ���Ļ��¿��� n��° ��� �̾Ƴ�(n��° ��Ҹ� �̾Ƴ� �� ����)

	cout << v[index - 1] << "\n";		// endl���� �ӵ�����
	return 0;
}