#include <iostream>
#include <cstring>
#include <algorithm>

/*
input
2
10

output
1
3

https://www.acmicpc.net/problem/1463

/* Copyright (C) 2017 by Son */

using namespace std;

int* dy;						// ��Ϳ��� �̹� ���� ������ �κ��� return�ϰ� ������ ���ؼ�

int recursive_solve(int num)
{
	if (num == 1) {				// 1�� �� ���� �� 0 �ֳĸ� return �� �� 1 �����ֹǷ�
		return 0;
	}
	if (dy[num - 1] > 0) {		// �̹� ���� �����ϸ� return
		return dy[num - 1];
	}
	if (dy[num - 2] == 0) {		// n-1 ���� �������� ������ �� ����
		dy[num - 2] = recursive_solve(num - 1);
	}
	if (num % 3 == 0) {			// 3���� ������ ������ �� 3���� ���� �� �ƴϸ� -1�� ���� ���� ��(dy[num-2])(���� �ؼ� 2�� ��� ������ �� �����Ƿ�)
		return (dy[num - 1] = 1 + min(recursive_solve(num / 3), dy[num - 2]));
	}
	else if(num % 2 == 0){		// 2�� ������ ������ �� 2�� ������ -1�� ���� ���� ��
		return (dy[num - 1] = 1 + min(recursive_solve(num / 2), dy[num - 2]));
	}
	else {
		return  (dy[num - 1] = 1 + dy[num - 2]);
	}
}

int main() {
	int num;
	int count = 0;

	cin >> num;
	
	dy = new int[num];

	memset(dy, 0, 4 * num);				// ��� <cstring> ��� �� 0���� �ʱ�ȭ (���� ����)

	cout << recursive_solve(num) << endl;
	
	delete[] dy;

	return 0;
}