#include <iostream>
#include <string>

/*
input
(()[[]])([])
output
28

https://www.acmicpc.net/problem/2504
*/

using namespace std;

template <class T>
class stack {
private:
	T arr[30];
	int stack_pointer;
public:
	stack() {
		this->stack_pointer = 0;
	}
	void push(T value) {
		arr[stack_pointer++] = value;
	}
	T pop() {
		if (!this->stack_pointer) {
			return 0;
		}
		return arr[--stack_pointer];
	}
	int size() {
		return this->stack_pointer;
	}
	int top() {
		if (!this->stack_pointer) {
			return -1;
		}
		return arr[stack_pointer - 1];
	}
	int empty() {
		if (!this->stack_pointer) {
			return 1;
		}
		return 0;
	}
};

long long pow(int a, int b) {
	long long result = 1;

	for (int i = 0; i < b; i++) {
		result *= a;
	}
	return result;
}

int main(void)
{
	int i, len, sur1 = 0, sur2 = 0, flag = 0;
	long long result = 0;
	char temp;
	string str;

	cin >> str;
	len = str.length();

	stack<char>* stk = new stack<char>();

	for (i = 0; i < len; i++) {
		temp = str[i];
		if (temp == '(' || temp == '[') {
			if (temp == '(') {
				flag = 1;
				sur1 += 1;
			}
			else {
				flag = 1;
				sur2 += 1;
			}
			stk->push(temp);
		}
		else if (temp == ')') {
			if (stk->pop() == '(') {
				sur1--;
				if (flag) {
					result += pow(2, sur1) * pow(3, sur2) * 2;
				}
				flag = 0;
			}
			else {
				cout << 0 << endl;
				delete stk;
				return 0;
			}
		}
		else if (temp == ']') {
			if (stk->pop() == '[') {
				sur2--;
				if (flag) {
					result += pow(2, sur1) * pow(3, sur2) * 3;
				}
				flag = 0;
			}
			else {
				cout << 0 << endl;
				delete stk;
				return 0;
			}
		}
	}
	if (!stk->empty()) {
		cout << 0 << endl;
		delete stk;
		return 0;
	}
	cout << result << endl;

	delete stk;
	return 0;
}