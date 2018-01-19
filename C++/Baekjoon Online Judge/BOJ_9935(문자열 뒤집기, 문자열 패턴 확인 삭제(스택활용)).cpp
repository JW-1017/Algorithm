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

// 문자열과 pattern에서 다음 번째 어떤 문자인지 저장(몇번째인지)
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
		if (total[i] == pattern[j]) {		// 패턴하고 같으면
			j++;
			s_stack.push(new char_help(j, total[i]));		// 다음번째와 함께 저장
			if (j == length2) {								// 길이까지 왔으면 다 빼냄
				for (k = 0; k < length2; k++) {
					s_stack.pop();
				}
				if (!s_stack.empty()) {						// 스택이 남아있지 않으면 앞에거 다음이 패턴 몇번째인지 확인
					j = s_stack.top()->len;
				}
				else {										// 비었으면 0으로 패턴 처음부터 비교
					j = 0;
				}
			}
		}
		else if (total[i] == pattern[0]) {					// 처음 패턴과 같으면 일단 저장 (후에 비교하므로)
			j = 1;
			s_stack.push(new char_help(1, pattern[0]));
		}
		else {												// 같지 않은 경우
			if (!s_stack.empty()) {								// 스택이 비어있찌 않으면 다빼내기
				s_stack.push(new char_help(++j, total[i]));
				while (!s_stack.empty()) {						// 빌 때까지 다 빼고 문자열 만들고 뒤집어서 결과에 더하기(스택이라 문자열 뒤부터 빼어짐) 
					j = s_stack.top()->len;
					for (k = j; k > 0; k--) {
						temp += s_stack.top()->c;
						s_stack.pop();
					}
				}
				reverse(temp.begin(), temp.end());				// 문자열 뒤집기
				result += temp;
			}
			else {
				result += total[i];								// 같으면 그냥 더함
			}
			j = 0;
			temp = "";
		}
	}
	if (!s_stack.empty()) {										// 다 끝나고도 스택 남아있으면 빼서 결과에 더함(뒤집어서)
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