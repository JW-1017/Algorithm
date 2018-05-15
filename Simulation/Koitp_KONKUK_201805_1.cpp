#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <map>
#include <set>
#include <cmath>
#include <list>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>

using namespace std;
/*
숫자의 나열 중에 첫 번째 번호부터 더해가며 만든 숫자열이 몇번 존재하나
확인해서 가장긴 숫자열의 길이 출력

input:
8
1 2 3 1 2 3 1 2

output:
2

https://koitp.org/problem/KONKUK_201805_1/read/
/* Copyright (C) 2018 by Son J.W*/

int n, m;
int a[3000];
int b[3000];
queue<int> ans[2];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, ind, maxv = 0, sel, sel2;
	m = 1;
	cin >> n;
	cin >> a[0];
	// 한 글자로 위치 같아지는 순간 저장
	ans[1].push(0);
	for (i = 1; i < n; i++) {
		cin >> a[i];
		if (a[0] == a[i]) {
			ans[1].push(i);
		}
	}
	maxv = ans[1].size();

	b[0] = a[0];
	// 2개의 큐로 번갈아가면서 저장
	for (i = 1; i < n; i++) {
		sel = i % 2;
		sel2 = (i + 1) % 2;
		b[i] = a[i];
		m++;
		// 위치 꺼내서 추가된 위치가 같은지 확인
		while (!ans[sel].empty()) {
			ind = ans[sel].front();
			ans[sel].pop();
			if (a[ind + m - 1] == b[i]) {
				// 같으면 또 다른 큐에 저장
				ans[sel2].push(ind);
			}
		}
		// 최대 크기보다 작아지는 순간이 있으면 break;
		if (maxv > (int)ans[sel2].size()) {
			break;
		}
	}
	// 길이 끝까지 비교한게 아니라 도중에 break 한거면 이전 길이로
	if (m != n) {
		m--;
	}
	cout << m << "\n";
	return 0;
}