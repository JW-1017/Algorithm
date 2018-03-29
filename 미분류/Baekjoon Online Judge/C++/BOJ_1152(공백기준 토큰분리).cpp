#include <iostream>
#include <string>
#include <sstream>

/*
input
The Curious Case of Benjamin Button
output
6

https://www.acmicpc.net/problem/1152

/* Copyright (C) 2017 by Son */

using namespace std;

int main(void)
{
	string str;
	string temp;
	int num = 0;
	getline(cin, str);

	stringstream stream(str);

	while (stream >> temp) {
		num++;
	}

	cout << num << endl;

	return 0;
}