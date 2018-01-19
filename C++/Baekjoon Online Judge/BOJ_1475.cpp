#include <cstdio>
#include <string>
#include <sstream>

#pragma warning(disable:4996)
/*
input
66669

output
3

https://www.acmicpc.net/problem/1475

/* Copyright (C) 2017 by Son */

using namespace std;

int arr[10];
int set = 0;

void buy_set() {
	for (int i = 0; i < 10; i++) {
		if (i == 6 || i == 9) {
			arr[i] += 2;
		}
		else {
			arr[i]++;
		}
	}
	set++;
}
int main() {
	int i, num, temp;
	string str;
	stringstream change;

	buy_set();
	scanf("%d", &num);

	change << num;
	str = change.str();
	num = str.length();
	
	for (i = 0; i < num; i++) {
		temp = str[i] - '0';
		if (arr[temp] == 0) {
			buy_set();
		}
		if (temp == 6 || temp == 9) {
			arr[6]--;
			arr[9]--;
		}
		else {
			arr[temp]--;
		}
	}
	printf("%d\n", set);
	return 0;
}