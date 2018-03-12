#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <map>
#include <set>
#include <list>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <numeric>
#include <cmath>
#include <unordered_set>
#include <unordered_map>

#pragma warning(disable:4996)

/*
input
7 1 2 3 4 5 6 7
8 1 2 3 5 8 13 21 34
0

output
1 2 3 4 5 6
1 2 3 4 5 7
1 2 3 4 6 7
1 2 3 5 6 7
1 2 4 5 6 7
1 3 4 5 6 7
2 3 4 5 6 7

1 2 3 5 8 13
1 2 3 5 8 21
1 2 3 5 8 34
1 2 3 5 13 21
1 2 3 5 13 34
1 2 3 5 21 34
1 2 3 8 13 21
1 2 3 8 13 34
1 2 3 8 21 34
1 2 3 13 21 34
1 2 5 8 13 21
1 2 5 8 13 34
1 2 5 8 21 34
1 2 5 13 21 34
1 2 8 13 21 34
1 3 5 8 13 21
1 3 5 8 13 34
1 3 5 8 21 34
1 3 5 13 21 34
1 3 8 13 21 34
1 5 8 13 21 34
2 3 5 8 13 21
2 3 5 8 13 34
2 3 5 8 21 34
2 3 5 13 21 34
2 3 8 13 21 34
2 5 8 13 21 34
3 5 8 13 21 34

https://www.acmicpc.net/problem/6603
/* Copyright (C) 2018 by Son */

using namespace std;

int n;
bool arr[13];			// 이거의 순열을 통한 조합 획득
int val[13];
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, sel;
	while (1) {
		cin >> sel;
		if (sel == 0) {
			break;
		}
		// 1 여섯개로 위치를 조정, 1인 위치만 출력
		for (i = 0; i < 6; i++) {
			arr[i] = 1;
			cin >> val[i];
		}
		for (i = 6; i < sel; i++) {
			arr[i] = 0;
			cin >> val[i];
		}
		do {
			for (i = 0; i < sel; i++) {
				if (arr[i]) {
					cout << val[i] << " ";
				}
			}
			cout << "\n";
		}while(prev_permutation(arr, arr + sel));
		cout << "\n";
	}
	return 0;
}