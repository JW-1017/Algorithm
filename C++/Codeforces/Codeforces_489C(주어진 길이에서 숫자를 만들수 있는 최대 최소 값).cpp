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
길이 m(ex 2), 합 s(ex 15)를 만들수 있는 숫자 최대 최소
input
2 15

output
69 96

http://codeforces.com/problemset/problem/489/C
/* Copyright (C) 2018 by Son */

using namespace std;

long repeated_squaring(long base, long exp)
{
	long result = 1;
	while (exp) {		// not zero
		if (exp % 2) {		// remain == 1
			result *= base;
		}
		base *= base;
		exp = exp /= 2;
	}
	return result;
}
vector<int> int_to_vector(long long num)
{
	vector<int> v;
	while (1) {
		if (num == 0) {
			return v;
		}
		v.insert(v.begin(), num % 10);
		num /= 10;
	}
}
string replace_all(const string& message, const string& pattern, const string& replace) {
	string result = message;
	string::size_type pos = 0;
	string::size_type offset = 0;
	int p_len = pattern.length();
	int r_len = replace.length();

	while ((pos = result.find(pattern, offset)) != string::npos) {
		result.replace(result.begin() + pos, result.begin() + pos + p_len, replace);
		offset = pos + r_len;
	}
	return result;
}
int main() {
	ios::sync_with_stdio(false);
	bool flag1 = 0, flag2 = 0;
	int m, s, s2;
	cin >> m >> s;
	s2 = s;
	int* max_val = new int[m];
	int* min_val = new int[m];

	// 최대 수로 자릿수만큼 곱한 값이 s보다 작거나 s가 0 인데 길이가 1이 아닐때
	if (m * 9 <  s || (s == 0 && m != 1)) {
		cout << "-1 -1\n";
		return 0;
	}
	for (int j = 0; j < m; j++) {
		// flag1 은 max_val 생성완료에 대한 값, flag2 은 min_val 생성완료에 대한 값
		// s(max_val에서 사용하는 목표 합) 이 0만 남으면 나머지를 0으로 채움
		if (s == 0 && !flag1) {
			for (int i = j; i < m; i++) {
				max_val[i] = 0;
			}
			// flag1 변경을 통해 더이상 관여 안함
			flag1 = 1;
		}
		// 0번째 위치에 오면(min_val은 뒤에서 부터 채움) 해당 값을 나머지 값으로
		if (j == m - 1 && !flag2) {
			min_val[0] = s2;
			// flag2 변경을 통해 더이상 관여 안함
			flag2 = 1;
		}
		// s2(min_val에서 사용하는 목표 합)이 1만 남으면 나머지 0으로 채우고 맨 앞자리 1
		else if (s2 == 1 && !flag2) {
			for (int i = m - j - 1; i > 0; i--) {
				min_val[i] = 0;
			}
			// 처음 값 1
			min_val[0] = 1;
			flag2 = 1;
		}
		// 아직 max_val에 대한 생성이 끝나지 않으면
		if (!flag1) {
			for (int i = 9; i > 0; i--) {
				// 9부터 시작해서 0까지 줄여나가며 값을 정함(앞에서 부터 큰 값 세팅)
				if (s - i >= 0) {
					s -= i;
					max_val[j] = i;
					break;
				}
			}
		}
		// 아직 min_val에 대한 생성이 끝나지 않으면
		if (!flag2) {
			for (int i = 9; i >= 1; i--) {
				// 9부터 시작해서 1까지 줄여나가며 값을 정함(뒤에서 부터 큰 값 세팅)
				if (s2 - i > 0) {
					// 0이 될 때는 따로 처리해줌
					min_val[m - j - 1] = i;
					s2 -= i;
					break;
				}
			}
		}
		if (flag1 && flag2) {
			break;
		}
	}
	for (int i = 0; i < m; i++) {
		cout << min_val[i];
	}
	cout << " ";
	for (int i = 0; i < m; i++) {
		cout << max_val[i];
	}
	cout << "\n";
	return 0;
}