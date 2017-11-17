#include <cstdio>
#include <vector>
#include <limits>
#include <algorithm>

#pragma warning(disable:4996)
/*
input
3
26 40 83
49 60 57
13 89 99

output
96

https://www.acmicpc.net/problem/1149

/* Copyright (C) 2017 by Son */

using namespace std;

class house {
public:
	int color[3];

	house(int red, int green, int blue) {
		this->color[0] = red;
		this->color[1] = green;
		this->color[2] = blue;
	}
};

int v_size;
vector<house> town;

int reculsive_solve(int num, int count) {
	if (count == v_size - 1) {
		return town[count].color[num];
	}
	return town[count].color[num] + min(reculsive_solve(((num + 1) % 3), count + 1), reculsive_solve(((num + 2) % 3), count + 1));
}

int main() {
	int i, num;
	int red, green, blue;
	int result = numeric_limits<int>::max();

	scanf("%d", &num);

	for (i = 0; i < num; i++) {
		scanf("%d%d%d", &red, &green, &blue);
		town.push_back(house(red, green, blue));
	}
	v_size = num;
	for (i = 0; i < 3; i++) {
		result = min(result, reculsive_solve(i, 0));
	}
	printf("%d\n", result);
	return 0;
}