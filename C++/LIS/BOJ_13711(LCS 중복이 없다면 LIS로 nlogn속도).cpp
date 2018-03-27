#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <map>
#include <set>
#include <list>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <numeric>
#include <cmath>
#include <unordered_set>
#include <unordered_map>

#pragma warning(disable:4996)

/*
input 
3
1 2 3
1 3 2

output
2

https://www.acmicpc.net/problem/13711
/* Copyright (C) 2018 by Son J.W*/

using namespace std;

/*
LCS �ΰ� ���� LIS���� (������ �ߺ��� ��� ����)
ù ��° ������ A�� �ް� �ι�° �迭�� ���� ��ġ�ϴ� ���� C�� ����

ex) 
ù��° 2 3 1 4    A�迭�� �״��
�ι�° 2 1 4 3    C[1] = 1, C[2] = 0, C[3] = 3, C[4] = 2

���� B�迭�� A�迭�� ���� ��ġ�ϴ� C�迭���� ��ġ�� A���� �տ������� B�迭�� ����

ex) C[A[0]] = 0 (2�� �ι�° �迭���� ��ġ�ϴ� ��Ҵ� 0) C[A[1]] = 3
    C[A[2]] = 1   C[A[3]] = 2    �̷ν� ù��° �迭�� ���� �ι�° �迭������ ��ġ�� ������

�̸� ���� �����ϴ� �κм����� Ȯ�� (LIS��)
lower_bound�� Ȱ���ؼ� �ᱹ nlogn �� �ð����⵵
*/

int A[100000];
int B[100000];
int C[100001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, n, temp = 1;
	int* ptr;
	cin >> n;

	for (i = 0; i < n; i++) {
		// ù��° �迭
		cin >> A[i];
	}
	// C�迭�� �ι�° �迭 ���� ��ġ�� ���� index�� ����
	for (i = 0; i < n; i++) {
		cin >> temp;
		C[temp] = i;
	}
	// B�迭�� A�迭�� �տ��������� ���� ��ġ�ϴ� ���� �ι�° �迭�� ��ġ
	for (i = 0; i < n; i++) {
		B[i] = C[A[i]];
	}
	// B�迭�� ���� LIS (A�迭�� �ٽ�(A �迭�� LIS�� ���� �迭�� �ٽ�))
	temp = 1;	// �� �ʱ�ȭ
	A[0] = B[0];
	for (i = 1; i < n; i++) {
		// A�迭�� �ִ밪���� ũ�� �߰�
		if (A[temp - 1] < B[i]) {
			A[temp] = B[i];
			// ũ�� �߰�
			temp++;
		}
		// ������
		else {
			// �ڽź��� ��������(ũ�ų�����)��ġ�� ���� ������
			ptr = lower_bound(A, A + temp, B[i]);
			*ptr = B[i];
		}
	}
	// ������ ��ŭ 
	cout << temp << "\n";
	return 0;
}