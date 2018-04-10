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

/*
처음 시작점을 어디로 잡든 최소값의 결과는 똑같다!!
(이것 때문에 고생함, 결국 돌아오는 경로기 때문)

해당 정점일 때랑 방문위치(비트로 저장)를 저장해가며 풀기

input
4
0 10 15 20
5  0  9 10
6 13  0 12
8  8  9  0

output
35

https://www.acmicpc.net/problem/2098
/* Copyright (C) 2018 by Son J.W*/

using namespace std;

typedef vector<int> jw;
typedef pair<int, int> pi;
// unoredered_map으로 한 이유는 출발지에서 도착지로 가는 경로로 값을 바로 접근하려고
typedef vector<unordered_map<int, int>> vvpii;

int n, en;
// 행 출발지 열 도착지 값 비용
vvpii adj;
// 행 도착지 열 방문 상태 일 때 이후 진행 되는 최소값 저장
int arr[16][1 << 16];

// a 출발지, vis 방문
int tsp(int a, int vis) {
	if (vis == en) {
		if (adj[a].find(0) != adj[a].end()) {
			arr[a][vis] = adj[a][0];
			return adj[a][0];
		}
		// 출발지로 가는 값이 없으면 무한대값 (임계값이상) 반환
		return (int)1e8;
	}
	int loc, minv = (int)1e8;
	int& ref = arr[a][vis];
	if (ref != 0) {
		return ref;
	}
	for (pi k : adj[a]) {
		loc = (1 << k.first);
		// 같은 경로면 무시
		if (vis & loc) {
			continue;
		}
		// 해당 도착지로 가능 경로 + 
		ref = k.second;
		// 그 밑으로 쭉
		ref += tsp(k.first, vis | loc);
		minv = min(ref, minv);
	}
	ref = minv;
	return ref;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j, a, minv = (int)1e8;
	cin >> n;
	en = 1 << n;
	en--;
	adj = vvpii(n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> a;
			// 0일 때 무시
			if (!a) {
				continue;
			}
			adj[i].insert(pi(j, a));
		}
	}
	// 시작점 임의의 점으로
	cout << tsp(0, 1) << "\n";
	return 0;
}