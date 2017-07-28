#include <iostream>
#include <algorithm>
#include <cstring>

/*
input
18

output
4

https://www.acmicpc.net/problem/2839

/* Copyright (C) 2017 by Son */

using namespace std;

int arr[5000];

int reculsive_solve(int total) {
	if (total == 0) {
		return 0;
	}
	else if (total == 1 || total == 2) {
		return 1000000;
	}
	if (arr[total - 1] > 0) {
		return arr[total - 1];
	}
	return (arr[total - 1] = 1 + min(reculsive_solve(total - 3), reculsive_solve(total - 5)));
}

int main() {
	int total;
	
	memset(arr, 0, 4 * 5000);

	cin >> total;

	total = reculsive_solve(total);

	if (total > 2000) {
		total = -1;
	}
	cout << total << endl;
	return 0;
}