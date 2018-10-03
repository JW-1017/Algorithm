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
#include <sstream>

using namespace std;

/*
입력의 첫 줄에는 테스트케이스 수를 나타내는 자연수 T가 주어진다. 
각 테스트케이스 별로 첫 줄에는 날의 수를 나타내는 자연수 N(2 ≤ N ≤ 1,000,000)이 주어지고, 
둘째 줄에는 날 별 주가를 나타내는 N개의 자연수들이 공백으로 구분되어 순서대로 주어진다. 
날 별 주가는 10,000이하다.
input:
3
3
10 7 6
3
3 5 9
5
1 1 3 1 2

각 테스트케이스 별로 최대 이익을 나타내는 정수 하나를 출력한다. 
답은 부호있는 64bit 정수형으로 표현 가능하다.
output:
0
10
5

https://www.acmicpc.net/problem/11501
/* Copyright (C) 2018 by Son J.W*/

typedef pair<int, int> pa;
typedef vector<int> jw;

int arr[1000000];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j, test;
	int day, temp;
	long long benefit;
	cin >> test;
	for (i = 0; i < test; i++) {
		benefit = 0;
		cin >> day;
		for (j = 0; j < day; j++) {
			cin >> arr[j];
		}
		temp = arr[day - 1];
		// 뒤부터 돌며 최대값이 갱신될때 변경 (현재로부터 최대이익 파악)
		for (j = day - 2; j >= 0; j--) {
			if (arr[j] < temp) {
				benefit += temp - arr[j];
			}
			else if(arr[j] > temp){
				temp = arr[j];
			}
		}
		cout << benefit << "\n";
	}
	return 0;
}