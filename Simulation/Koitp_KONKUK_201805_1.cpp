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
������ ���� �߿� ù ��° ��ȣ���� ���ذ��� ���� ���ڿ��� ��� �����ϳ�
Ȯ���ؼ� ����� ���ڿ��� ���� ���

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
	// �� ���ڷ� ��ġ �������� ���� ����
	ans[1].push(0);
	for (i = 1; i < n; i++) {
		cin >> a[i];
		if (a[0] == a[i]) {
			ans[1].push(i);
		}
	}
	maxv = ans[1].size();

	b[0] = a[0];
	// 2���� ť�� �����ư��鼭 ����
	for (i = 1; i < n; i++) {
		sel = i % 2;
		sel2 = (i + 1) % 2;
		b[i] = a[i];
		m++;
		// ��ġ ������ �߰��� ��ġ�� ������ Ȯ��
		while (!ans[sel].empty()) {
			ind = ans[sel].front();
			ans[sel].pop();
			if (a[ind + m - 1] == b[i]) {
				// ������ �� �ٸ� ť�� ����
				ans[sel2].push(ind);
			}
		}
		// �ִ� ũ�⺸�� �۾����� ������ ������ break;
		if (maxv > (int)ans[sel2].size()) {
			break;
		}
	}
	// ���� ������ ���Ѱ� �ƴ϶� ���߿� break �ѰŸ� ���� ���̷�
	if (m != n) {
		m--;
	}
	cout << m << "\n";
	return 0;
}