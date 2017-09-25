#include <cstdio>
#include <vector>
#include <functional>
#include <queue>

#pragma warning(disable: 4996)

/*
input:
7
1
5
2
10
-99
7
5

output:
1
1
2
2
2
2
5

https://www.acmicpc.net/problem/1655
/* Copyright (C) 2017 by Son */

using namespace std;

int main() {
	int i, num, value, temp;

	priority_queue<int, vector<int>, less<int>> small_q;	// �߰� ������ ������ ���� top �� �߰���
	priority_queue<int, vector<int>, greater<int>> big_q;	// �߰� ������ ū ���� top�� �߰��� ���� ��

	scanf("%d", &num);

	for (i = 0; i < num; i++) {
		scanf("%d", &value);

		if (big_q.size() == small_q.size()) {
			if (big_q.size() == 0 && small_q.size() == 0) {
				small_q.push(value);
			}
			else {
				if ((temp = big_q.top()) < value) {
					big_q.pop();
					big_q.push(value);
					small_q.push(temp);
				}
				else {
					small_q.push(value);
				}
			}
		}
		else if (big_q.size() < small_q.size()) {
			if ((temp = small_q.top()) > value) {
				small_q.pop();
				small_q.push(value);
				big_q.push(temp);
			}
			else {
				big_q.push(value);
			}
		}
		printf("%d\n", small_q.top());
	}

	return 0;
}