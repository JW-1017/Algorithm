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
input:
8 50 4 7
2
7
9
25
7
9
7
30

output:
4

https://www.acmicpc.net/problem/15961
/* Copyright (C) 2018 by Son J.W*/

typedef pair<int, int> pa;
typedef vector<int> jw;

vector<int> arr;
int type[3001];

// set�� Ȱ���Ͽ� �ߺ�����, ������ �� �ش� ��ȣ ������ �����Ͽ� ������ 0�� ���� ����
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, d, k, c, i, point = 0;
	int maxv = 0, end;

	cin >> n >> d >> k >> c;

	arr = jw(n);

	unordered_set<int> s;
	s.insert(c);
	type[c]++;

	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (i = 0; i < k; i++) {
		s.insert(arr[i]);
		type[arr[i]]++;
		// ������ ���� ���ƿ��� �� ����
		arr.push_back(arr[i]);
	}
	maxv = s.size();

	for (i = k; i < n; i++) {
		type[arr[point]]--;
		if (type[arr[point]] == 0) {
			s.erase(arr[point]);
		}
		s.insert(arr[i]);
		type[arr[i]]++;
		maxv = max(maxv, (int)s.size());
		point++;
	}
	end = arr.size();
	
	// ���� ���� �������� �����Ͽ� ���� �� �߰�
	for (i = n; i < end-1; i++) {
		type[arr[point]]--;
		if (type[arr[point]] == 0) {
			s.erase(arr[point]);
		}
		s.insert(arr[i]);
		type[arr[i]]++;
		maxv = max(maxv, (int)s.size());
		point++;
	}

	cout << maxv << "\n";
	return 0;
}