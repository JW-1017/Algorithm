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
4 6
a t c i s w

output
acis
acit
aciw
acst
acsw
actw
aist
aisw
aitw
astw
cist
cisw
citw
istw

https://www.acmicpc.net/problem/1759
/* Copyright (C) 2018 by Son */

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
		
	char k;
	string str = "";
	int i, l, c;
	cin >> l >> c;

	bool* flag = new bool[c];
	for (i = 0; i < l; i++) {
		flag[i] = 1;
	}
	for (i = l; i < c; i++) {
		flag[i] = 0;
	}

	for (i = 0; i < c; i++) {
		cin >> k;
		str += k;
	}
	sort(str.begin(), str.end());
	do {
		int jw = 0;
		string temp = "";
		// flag 를 활용한 prev_combination
		for (i = 0; i < c; i++) {
			if (flag[i]) {
				k = str[i];
				if (k == 'a' || k == 'e' || k == 'i' || k == 'o' || k == 'u') {
					jw++;
				}
				temp += k;
			}
		}
		if (jw && (l - jw >= 2)) {
			cout << temp << "\n";
		}
	} while (prev_permutation(flag, flag + c));
	return 0;
}