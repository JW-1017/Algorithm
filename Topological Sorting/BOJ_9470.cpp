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
input 
1
1 7 8
1 3
2 3
6 4
3 4
3 5
6 7
5 7
4 7

output
1 3

https://www.acmicpc.net/problem/9470
/* Copyright (C) 2018 by Son J.W*/

using namespace std;

// 차수
int ind[1001];
// 최대값
int cnt[1001];
// 2개이상 모였는지
bool flag[1001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);		
	int c, num, i, v, e, st, en, s, temp, mav = 0;
	queue<int> q;
	cin >> c;
	for (s = 0; s < c; s++) {
		cin >> num >> v >> e;
		vector<vector<int>> adj = vector<vector<int>>(v + 1);
		for (i = 0; i < e; i++) {
			cin >> st >> en;
			ind[en]++;
			adj[st].push_back(en);
		}
		for (i = 1; i <= v; i++) {
			if (!ind[i]) {
				// 시작 값이 1
				cnt[i]++;
				q.push(i);
			}
		}
		for (i = 1; i <= v; i++) {
			temp = q.front();
			q.pop();
			// 2개이상 모였으면 +1
			if (flag[temp]) {
				cnt[temp]++;
			}
			// 최대값 설정
			mav = max(mav, cnt[temp]);
			for (int k : adj[temp]) {
				ind[k]--;
				// 크면 flag = 0 , 최대값 갱신
				if (cnt[temp] > cnt[k]) {
					cnt[k] = cnt[temp];
					flag[k] = 0;
				}
				// 같으면 flag 1 최대값 그대로
				else if(cnt[temp] == cnt[k]){
					flag[k] = 1;
				}
				if (!ind[k]) {
					q.push(k);
				}
			}
		}
		cout << num << " " << mav << "\n";
		for (i = 1; i <= v; i++) {
			ind[i] = 0;
			cnt[i] = 0;
			flag[i] = 0;
		}
		mav = 0;
	}
	return 0;
}