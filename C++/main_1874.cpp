#include <iostream>
#include <string>
#include <stack>

/*
input
8
4
3
6
8
7
5
2
1

output
+
+
+
+
-
-
+
+
-
+
+
-
-
-
-
-

https://www.acmicpc.net/problem/1874

/* Copyright (C) 2017 by Son */

using namespace std;

int main(void)
{
	string result;
	int num, i, temp = 1;
	stack<int>* stk = new stack<int>();

	cin >> num;
	
	int* arr = new int[num];

	for (i = 0; i < num; i++) {
		cin >> arr[i];
	}
	i = 0;

	while(i < num) {
		// ���� 1���� num���� ���µ� ���� ���ڰ� �Է��� i��° ������ �۰ų� ���� �� push
		if (temp <= arr[i]) {				
			stk->push(temp);
			result += "+\n";
			temp++;
		}
		// Ŀ���� top�� ���ؼ� ������ pop �ƴϸ� �Ұ��� �� ����
		else if (temp > arr[i]) {
			if (stk->top() == arr[i]) {
				stk->pop();
				result += "-\n";
				i++;
			}
			else {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << result << endl;
	return 0;
}