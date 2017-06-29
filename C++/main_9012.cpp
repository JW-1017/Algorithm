#include <iostream>
#include <string>

/*
input
6
(())())
(((()())()
(()())((()))
((()()(()))(((())))()
()()()()(()()())()
(()((())()(

output
NO
NO
YES
NO
YES
NO

https://www.acmicpc.net/problem/9012
*/

using namespace std;

template <class T>
class stack {
private:
	T arr[50];
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
	void clear() {
		stack_pointer = 0;
	}
};

int main(void)
{
	int num, i = 0, j = 0, len;
	int out = 0;
	char temp;
	string str, result;

	cin >> num;
	stack<char>* stk = new stack<char>();

	for (; i < num; i++) {
		j = 0;
		cin >> str;
		len = str.length();

		for (; j < len; j++) {
			temp = str[j];
			if (temp == '(') {
				stk->push(temp);
			}
			else {
				if (stk->pop() == '(') {
					continue;
				}
				else {
					result += "NO\n";
					out = 1;
					break;
				}
			}
		}
		if (out) {
			out = 0;
			stk->clear();
			continue;
		}
		if (stk->empty()) {
			result += "YES\n";
		}
		else {
			result += "NO\n";;
		}
		stk->clear();
	}
	cout << result;
	return 0;
}