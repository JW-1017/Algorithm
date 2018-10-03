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
�Է��� ù �ٿ��� �׽�Ʈ���̽� ���� ��Ÿ���� �ڿ��� T�� �־�����. 
�� �׽�Ʈ���̽� ���� ù �ٿ��� ���� ���� ��Ÿ���� �ڿ��� N(2 �� N �� 1,000,000)�� �־�����, 
��° �ٿ��� �� �� �ְ��� ��Ÿ���� N���� �ڿ������� �������� ���еǾ� ������� �־�����. 
�� �� �ְ��� 10,000���ϴ�.
input:
3
3
10 7 6
3
3 5 9
5
1 1 3 1 2

�� �׽�Ʈ���̽� ���� �ִ� ������ ��Ÿ���� ���� �ϳ��� ����Ѵ�. 
���� ��ȣ�ִ� 64bit ���������� ǥ�� �����ϴ�.
output:
0
10
5

https://www.acmicpc.net/problem/11501
/* Copyright (C) 2018 by Son J.W*/

typedef pair<int, int> pa;
typedef vector<int> jw;

int arr[1000000];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j, test;
	int day, temp;
	long long benefit;
	cin >> test;
	for (i = 0; i < test; i++) {
		benefit = 0;
		cin >> day;
		for (j = 0; j < day; j++) {
			cin >> arr[j];
		}
		temp = arr[day - 1];
		// �ں��� ���� �ִ밪�� ���ŵɶ� ���� (����κ��� �ִ����� �ľ�)
		for (j = day - 2; j >= 0; j--) {
			if (arr[j] < temp) {
				benefit += temp - arr[j];
			}
			else if(arr[j] > temp){
				temp = arr[j];
			}
		}
		cout << benefit << "\n";
	}
	return 0;
}