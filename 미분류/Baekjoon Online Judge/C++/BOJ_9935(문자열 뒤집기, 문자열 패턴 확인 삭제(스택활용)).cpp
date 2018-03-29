#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

/*
input
mirkovC4nizCC44
C4

output
mirkovniz

https://www.acmicpc.net/problem/9935

/* Copyright (C) 2017 by Son */

using namespace std;

// ���ڿ��� pattern���� ���� ��° � �������� ����(���°����)
class char_help {
public:
	int len;
	char c;
	char_help(int len, char c) {
		this->len = len;
		this->c = c;
	}
};

int main() {
	int i = 0, j = 0, k, length1, length2;
	string total;
	string pattern;
	string temp = "";
	string result = "";
	stack<char_help*> s_stack;

	cin >> total;
	cin >> pattern;

	length1 = total.length();
	length2 = pattern.length();

	for (; i < length1; i++) {
		if (total[i] == pattern[j]) {		// �����ϰ� ������
			j++;
			s_stack.push(new char_help(j, total[i]));		// ������°�� �Բ� ����
			if (j == length2) {								// ���̱��� ������ �� ����
				for (k = 0; k < length2; k++) {
					s_stack.pop();
				}
				if (!s_stack.empty()) {						// ������ �������� ������ �տ��� ������ ���� ���°���� Ȯ��
					j = s_stack.top()->len;
				}
				else {										// ������� 0���� ���� ó������ ��
					j = 0;
				}
			}
		}
		else if (total[i] == pattern[0]) {					// ó�� ���ϰ� ������ �ϴ� ���� (�Ŀ� ���ϹǷ�)
			j = 1;
			s_stack.push(new char_help(1, pattern[0]));
		}
		else {												// ���� ���� ���
			if (!s_stack.empty()) {								// ������ ������� ������ �ٻ�����
				s_stack.push(new char_help(++j, total[i]));
				while (!s_stack.empty()) {						// �� ������ �� ���� ���ڿ� ����� ����� ����� ���ϱ�(�����̶� ���ڿ� �ں��� ������) 
					j = s_stack.top()->len;
					for (k = j; k > 0; k--) {
						temp += s_stack.top()->c;
						s_stack.pop();
					}
				}
				reverse(temp.begin(), temp.end());				// ���ڿ� ������
				result += temp;
			}
			else {
				result += total[i];								// ������ �׳� ����
			}
			j = 0;
			temp = "";
		}
	}
	if (!s_stack.empty()) {										// �� ������ ���� ���������� ���� ����� ����(�����)
		while (!s_stack.empty()) {
			temp += s_stack.top()->c;
			s_stack.pop();
		}
		reverse(temp.begin(), temp.end());
		result += temp;
	}
	if (result == "") {
		cout << "FRULA" << endl;
	}
	else {
		cout << result << endl;
	}
	return 0;
}