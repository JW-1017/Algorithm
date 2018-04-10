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
ó�� �������� ���� ��� �ּҰ��� ����� �Ȱ���!!
(�̰� ������ �����, �ᱹ ���ƿ��� ��α� ����)

�ش� ������ ���� �湮��ġ(��Ʈ�� ����)�� �����ذ��� Ǯ��

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
// unoredered_map���� �� ������ ��������� �������� ���� ��η� ���� �ٷ� �����Ϸ���
typedef vector<unordered_map<int, int>> vvpii;

int n, en;
// �� ����� �� ������ �� ���
vvpii adj;
// �� ������ �� �湮 ���� �� �� ���� ���� �Ǵ� �ּҰ� ����
int arr[16][1 << 16];

// a �����, vis �湮
int tsp(int a, int vis) {
	if (vis == en) {
		if (adj[a].find(0) != adj[a].end()) {
			arr[a][vis] = adj[a][0];
			return adj[a][0];
		}
		// ������� ���� ���� ������ ���Ѵ밪 (�Ӱ谪�̻�) ��ȯ
		return (int)1e8;
	}
	int loc, minv = (int)1e8;
	int& ref = arr[a][vis];
	if (ref != 0) {
		return ref;
	}
	for (pi k : adj[a]) {
		loc = (1 << k.first);
		// ���� ��θ� ����
		if (vis & loc) {
			continue;
		}
		// �ش� �������� ���� ��� + 
		ref = k.second;
		// �� ������ ��
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
			// 0�� �� ����
			if (!a) {
				continue;
			}
			adj[i].insert(pi(j, a));
		}
	}
	// ������ ������ ������
	cout << tsp(0, 1) << "\n";
	return 0;
}