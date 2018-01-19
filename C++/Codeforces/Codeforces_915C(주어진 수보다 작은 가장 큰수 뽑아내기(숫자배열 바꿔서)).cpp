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

	if (len2 > len) {			// ���� ��� �ι�° ���� ������ ŭ
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
			if ((temp = pq.top()) == v[i]) {		// �ִ� ���� ������ �ְ� ������ �Ǵ�
				pq.pop();
				arr[i] = temp;
			}
			else if (temp < v[i]) {					// ������ �׼������� ����Ȱ� + ���� pq���� ū��
				for (int j = 0; j < i; j++) {
					cout << arr[j];
				}
				cout << temp;
				pq.pop();							// temp�� pq.top()�̾����Ƿ�
				while (!pq.empty()) {
					cout << pq.top();
					pq.pop();
				}
				cout << "\n";
				return 0;
			}
			// Ŭ ��
			else {
				// ���簪�� �ӽ� queue�� ����
				q.push(temp);
				pq.pop();
				
				while (1) {
					// pq�� ����ִٴ°� ���� ��ġ���� ��� ���� ũ�ٴ°�
					if (pq.empty()) {
						// que �պκк��Ͱ� ū���̹Ƿ� ���������� ä�� �־�� ���� ����� �ִ� ������ ���� ��(limit���ٴ� ŭ)
						for (int j = len - 1; j >= i; j--) {
							arr[j] = q.front();
							q.pop();
						}
						// �ٷ� ���� ���� ����
						prev_permutation(arr, arr + len);
						// ���
						for (int j = 0; j < len; j++) {
							cout << arr[j];
						}
						cout << "\n";
						return 0;
					}
					// ������ �ְ� break;
					if ((temp = pq.top()) == v[i]) {
						pq.pop();
						arr[i] = temp;
						break;
					}
					// ������ ������ġ ���� ����ϰ�
					else if (temp < v[i]) {
						for (int j = 0; j < i; j++) {
							cout << arr[j];
						}
						pq.pop();
						cout << temp;
						// q�� �ִ°� ���(ū������ pq���� ŭ(pq���� ���°����� queue�� �����Ƿ�))
						while (!q.empty()) {
							cout << q.front();
							q.pop();
						}
						// ������ pq ū������� ���
						while (!pq.empty()) {
							cout << pq.top();
							pq.pop();
						}
						cout << "\n";
						return 0;
					}
					// ���� ũ�ٸ� queue�� �ְ� pq�� ����
					q.push(temp);
					pq.pop();
				}
				// ���� ���¿��� ������������ queue���� �ٽ� pq�� �־��� �ٽ� pq Ȱ��
				while (!q.empty()) {
					pq.push(q.front());
					q.pop();
				}
			}
		}
		// �� ���� �� ���
		for (int j = 0; j < len; j++) {
			cout << arr[j];
		}
		cout << "\n";
	}
	return 0;
}