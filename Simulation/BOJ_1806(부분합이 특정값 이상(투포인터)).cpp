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
/*
처음 시작점을 어디로 잡든 최소값의 결과는 똑같다!!
(이것 때문에 고생함, 결국 돌아오는 경로기 때문)

해당 정점일 때랑 방문위치(비트로 저장)를 저장해가며 풀기

input
10 15
5 1 3 5 10 7 4 9 2 8

output
2

https://www.acmicpc.net/problem/1806
/* Copyright (C) 2018 by Son J.W*/

using namespace std;
int arr[100000];
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j, n, num = 0, minv = 100000, st;
	long long m, sum = 0;
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	st = 0;
	sum += arr[0];
	num++;
	// 더하자 마자 최대가 되면 1출력
	if (sum >= m) {
		cout << "1\n";
		return 0;
	}
	for (i = 1; i < n; i++) {
		sum += arr[i];
		num++;
		// sum이 m보다 크거나 같으면
		if (sum >= m) {
			do {
				sum -= arr[st];
				// 작아질 때 까지 빼고
				if (sum < m) {
					// 더했을 때가 크거나 같을 때
					sum += arr[st];
					break;
				}
				num--;
				st++;
			} while (sum >= m);
			minv = min(minv, num);
		}
	}
	if (minv == 100000) {
		minv = 0;
	}
	cout << minv << "\n";
	return 0;
}