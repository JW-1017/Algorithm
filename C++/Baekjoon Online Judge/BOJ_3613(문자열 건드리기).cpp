#include <iostream>
#include <string>
#include <cctype>

/*
input
long_and_mnemonic_identifier

output
longAndMnemonicIdentifier

https://www.acmicpc.net/problem/3613
/* Copyright (C) 2017 by Son */

using namespace std;

int main() {
	int i, type = 0;
	int len;		// 1 c++ 2 java
	string str;
	string result = "";
	std::ios::sync_with_stdio(false);		// cin cout 성능향상

	cin >> str;
	len = str.length();

	if (str[0] == '_' || isupper(str[0])) {
		cout << "Error!\n";
		return 0;
	}
	result = str[0];
	for (i = 1; i < len; i++) {
		if (str[i] == '_') {
			if (type == 2) {
				result = "Error!";
				break;
			}
			if (i + 1 == len) {
				result = "Error!";
				break;
			}
			if (str[i + 1] == '_' || isupper(str[i+1])) {		// 연달아서 _ _ 나올때 랑 _ 뒤에 대문자
				result = "Error!";
				break;
			}
			result += toupper(str[++i]);
		}
		else if (isupper(str[i])) {
			if (type == 1) {
				result = "Error!";
				break;
			}
			result += '_';
			result += tolower(str[i]);
		}
		else {
			result += str[i];
		}
	}
	cout << result << "\n";
	return 0;
}