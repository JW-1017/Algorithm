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
3
1 2 3
1 3 2

output
2

https://www.acmicpc.net/problem/13711
/* Copyright (C) 2018 by Son J.W*/

using namespace std;

/*
LCS 인것 같은 LIS문제 (숫자의 중복이 없어서 가능)
첫 번째 베열을 A로 받고 두번째 배열의 값이 위치하는 곳을 C로 받음

ex) 
첫번째 2 3 1 4    A배열에 그대로
두번째 2 1 4 3    C[1] = 1, C[2] = 0, C[3] = 3, C[4] = 2

이후 B배열에 A배열의 값이 위치하는 C배열상의 위치를 A열의 앞에서부터 B배열에 저장

ex) C[A[0]] = 0 (2가 두번째 배열에서 위치하는 장소는 0) C[A[1]] = 3
    C[A[2]] = 1   C[A[3]] = 2    이로써 첫번째 배열의 수가 두번째 배열에서의 위치가 정해짐

이를 가장 증가하는 부분수열로 확인 (LIS로)
lower_bound를 활용해서 결국 nlogn 의 시간복잡도
*/

int A[100000];
int B[100000];
int C[100001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, n, temp = 1;
	int* ptr;
	cin >> n;

	for (i = 0; i < n; i++) {
		// 첫번째 배열
		cin >> A[i];
	}
	// C배열은 두번째 배열 값이 위치한 곳의 index를 저장
	for (i = 0; i < n; i++) {
		cin >> temp;
		C[temp] = i;
	}
	// B배열은 A배열의 앞에서부터의 값이 위치하는 곳의 두번째 배열의 위치
	for (i = 0; i < n; i++) {
		B[i] = C[A[i]];
	}
	// B배열에 대해 LIS (A배열로 다시(A 배열이 LIS를 위한 배열로 다시))
	temp = 1;	// 꼭 초기화
	A[0] = B[0];
	for (i = 1; i < n; i++) {
		// A배열의 최대값보다 크면 추가
		if (A[temp - 1] < B[i]) {
			A[temp] = B[i];
			// 크기 추가
			temp++;
		}
		// 작으면
		else {
			// 자신보다 작지않은(크거나같은)위치로 가서 값변경
			ptr = lower_bound(A, A + temp, B[i]);
			*ptr = B[i];
		}
	}
	// 사이즈 만큼 
	cout << temp << "\n";
	return 0;
}