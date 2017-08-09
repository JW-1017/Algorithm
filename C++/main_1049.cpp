#include <iostream>
#include <algorithm>

/*
input
4 2
12 3
15 4

output
12

https://www.acmicpc.net/problem/1049

/* Copyright (C) 2017 by Son */

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);		// cin cout 성능향상
	int i, num, brand, min_pack = 6006, min_one = 1001;
	int pack, one, price;

	cin >> num >> brand;

	for (i = 0; i < brand; i++) {
		cin >> pack >> one;
		min_pack = min(min_pack, pack);
		min_one = min(min_one, one);
	}
	if (min_pack > min_one * 6) {
		min_pack = min_one * 6;
	}
	price = (num / 6) * min_pack;
	if (min_pack < (num % 6) * min_one) {
		price += min_pack;
	}
	else {
		price += (num % 6) * min_one;
	}
	cout << price << endl;

	return 0;
}