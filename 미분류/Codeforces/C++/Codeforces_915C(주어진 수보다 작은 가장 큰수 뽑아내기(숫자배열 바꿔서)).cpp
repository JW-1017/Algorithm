#include <cstdio>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>

/*
input
123
222

output
213

http://codeforces.com/problemset/problem/915/C

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
		exp = exp >> 1;
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
priority_queue<int> int_to_pq(long long num)
{
	priority_queue<int> pq;
	while (1) {
		if (num == 0) {
			return pq;
		}
		pq.push(num % 10);
		num /= 10;
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	int i = 0, flag = 1;
	long long num, limit;

	cin >> num >> limit;
	int arr[20];
	priority_queue<int> pq = int_to_pq(num);
	vector<int> v = int_to_vector(limit);

	int len = pq.size();
	int len2 = v.size();

	if (len2 > len) {			// 길이 길면 두번째 수가 무조건 큼
		for (i = 0; i < len; i++) {
			cout << pq.top();
			pq.pop();
		}
		cout << "\n";
		return 0;
	}
	else{
		int temp;
		queue<int> q;
		for (i = 0; i < len; i++) {
			if ((temp = pq.top()) == v[i]) {		// 최대 값과 같으면 넣고 다음거 판단
				pq.pop();
				arr[i] = temp;
			}
			else if (temp < v[i]) {					// 작으면 그순간까지 저장된값 + 이후 pq에서 큰값
				for (int j = 0; j < i; j++) {
					cout << arr[j];
				}
				cout << temp;
				pq.pop();							// temp가 pq.top()이었으므로
				while (!pq.empty()) {
					cout << pq.top();
					pq.pop();
				}
				cout << "\n";
				return 0;
			}
			// 클 때
			else {
				// 현재값을 임시 queue에 넣음
				q.push(temp);
				pq.pop();
				
				while (1) {
					// pq가 비었있다는건 현재 위치에서 모든 수가 크다는것
					if (pq.empty()) {
						// que 앞부분부터가 큰수이므로 역방향으로 채워 넣어야 현재 만들수 있는 수에서 작은 수(limit보다는 큼)
						for (int j = len - 1; j >= i; j--) {
							arr[j] = q.front();
							q.pop();
						}
						// 바로 직전 수를 구함
						prev_permutation(arr, arr + len);
						// 출력
						for (int j = 0; j < len; j++) {
							cout << arr[j];
						}
						cout << "\n";
						return 0;
					}
					// 같으면 넣고 break;
					if ((temp = pq.top()) == v[i]) {
						pq.pop();
						arr[i] = temp;
						break;
					}
					// 작으면 현재위치 까지 출력하고
					else if (temp < v[i]) {
						for (int j = 0; j < i; j++) {
							cout << arr[j];
						}
						pq.pop();
						cout << temp;
						// q에 있는값 출력(큰순서임 pq보다 큼(pq에서 나온값들이 queue에 갔으므로))
						while (!q.empty()) {
							cout << q.front();
							q.pop();
						}
						// 나머지 pq 큰순서대로 출력
						while (!pq.empty()) {
							cout << pq.top();
							pq.pop();
						}
						cout << "\n";
						return 0;
					}
					// 아직 크다면 queue에 넣고 pq값 빼기
					q.push(temp);
					pq.pop();
				}
				// 같은 상태에서 빠져나왔으면 queue값을 다시 pq에 넣어줌 다시 pq 활용
				while (!q.empty()) {
					pq.push(q.front());
					q.pop();
				}
			}
		}
		// 다 같을 때 출력
		for (int j = 0; j < len; j++) {
			cout << arr[j];
		}
		cout << "\n";
	}
	return 0;
}