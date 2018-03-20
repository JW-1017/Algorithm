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
10
5 10 11 12 13 30 35 40 45 47

output
50

https://www.acmicpc.net/problem/11052
/* Copyright (C) 2018 by Son */

using namespace std;

int arr[1001];

/*
1 2 3 4 5 6 7 8 9 ���ִٰ� ������ ��

2 �� 1+1 �� 2�� �ִ븦 ���´�
3 �� 2(1+1 or 2) + 1 �� 3�� �ִ븦 ����
4 �� 2(1+1 or 2) + 2(1+1 or 2), 3(2(1+1 or 2) + 1 or 3), 4 �� �ִ븦 ���´�
�ᱹ ���� ���� ��ġ�� �ִ븦 ���� �� ������ �ߺ��Ǵ� Ƚ������ ���ԵǴ� ��
*/

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, n;
	cin >> n;
	cin >> arr[1];
	// �����鼭 ������� �������� �� �ִ밪�� ����
	for (i = 2; i <= n; i++) {
		cin >> arr[i];
		int index = 1;
		while (1) {
			// ���� ó��(��������) �ε����� ���ϴµ� �Ѿ� �� ���� �ѹ� ���Ȱ� Ȥ�� ����ϸ� �ȵǴ°�
			if (i - index < index) {
				break;
			}
			// �ִ븦 ���ϰ�
			arr[i] = max(arr[i], arr[i - index] + arr[index]);
			// ���ϴ� ��ġ ����
			index++;
		}
	}
	cout << arr[n] << "\n";
	return 0;
}