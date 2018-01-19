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
		// 현재 1부터 num까지 가는데 현재 숫자가 입력한 i번째 수보다 작거나 같을 때 push
		if (temp <= arr[i]) {				
			stk->push(temp);
			result += "+\n";
			temp++;
		}
		// 커지면 top과 비교해서 같으면 pop 아니면 불가능 한 것임
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