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
10
5 10 11 12 13 30 35 40 45 47

output
50

https://www.acmicpc.net/problem/11052
/* Copyright (C) 2018 by Son */

using namespace std;

int arr[1001];

/*
1 2 3 4 5 6 7 8 9 가있다고 가정할 때

2 는 1+1 과 2의 최대를 갖는다
3 은 2(1+1 or 2) + 1 과 3의 최대를 갖고
4 는 2(1+1 or 2) + 2(1+1 or 2), 3(2(1+1 or 2) + 1 or 3), 4 중 최대를 갖는다
결국 현재 까지 위치의 최대를 갖을 때 여러번 중복되는 횟수까지 포함되는 것
*/

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, n;
	cin >> n;
	cin >> arr[1];
	// 넣으면서 현재까지 구매했을 시 최대값을 넣음
	for (i = 2; i <= n; i++) {
		cin >> arr[i];
		int index = 1;
		while (1) {
			// 끝과 처음(좁혀나감) 인덱스를 더하는데 넘어 설 때는 한번 계산된것 혹은 계산하면 안되는것
			if (i - index < index) {
				break;
			}
			// 최대를 구하고
			arr[i] = max(arr[i], arr[i - index] + arr[index]);
			// 더하는 위치 증가
			index++;
		}
	}
	cout << arr[n] << "\n";
	return 0;
}