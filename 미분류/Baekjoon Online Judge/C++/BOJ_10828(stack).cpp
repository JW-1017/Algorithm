#include <iostream>
#include <sstream>
#include <string>

/* Copyright (C) 2017 by Son */

using namespace std;

template <class T>
class stack {
private:
	T arr[10000];
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
			return -1;
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
		return arr[stack_pointer-1];
	}
	int empty() {
		if (!this->stack_pointer) {
			return 1;
		}
		return 0;
	}
};

int main(void)
{
	int i = 0, num, temp;
	string str;
	stringstream result;

	stack<int>* stk = new stack<int>();

	cin >> num;

	for (i = 0; i < num; i++) {
		cin >> str;
		if (str == "push") {
			cin >> temp;
			stk->push(temp);
		}
		else if (str == "top") {
			result << stk->top() << endl;
		}
		else if (str == "size") {
			result << stk->size() << endl;
		}
		else if (str == "empty") {
			result << stk->empty() << endl;
		}
		else if (str == "pop") {
			result << stk->pop() << endl;
		}
	}
	str = result.str();

	cout << str;
	return 0;
}