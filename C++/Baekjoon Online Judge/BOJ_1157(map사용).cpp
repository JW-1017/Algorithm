#include <iostream>
#include <string>
#include <cctype>
#include <map>

/*
input
Mississipi

output
?

https://www.acmicpc.net/problem/1157

/* Copyright (C) 2017 by Son */

using namespace std;

int main() {
	int i, length, count = 0;
	int result = 0;
	char temp_c;
	string temp;
	map<char, int> count_map;
	map<char, int>::iterator itMap;
	map<char, int>::iterator temp_map;

	cin >> temp;

	length = temp.length();

	for (i = 0; i < length; i++) {
		temp_c = temp[i];

		if (islower(temp_c)) {
			temp_c = toupper(temp_c);
		}

		if (count_map.find(temp_c) == count_map.end()) {
			count_map[temp_c] = 1;
		}
		else {
			count_map[temp_c]++;
		}
	}

	itMap = count_map.begin();

	for (; itMap != count_map.end(); itMap++) {
		if (itMap->second > result) {
			result = itMap->second;
			temp_c = itMap->first;
			temp_map = itMap;
		}
	}

	temp_map++;

	for (; temp_map != count_map.end(); temp_map++) {
		if (temp_map->second == result) {
			cout << '?' << endl;
			return 0;
		}
	}
	cout << temp_c << endl;
	return 0;
}