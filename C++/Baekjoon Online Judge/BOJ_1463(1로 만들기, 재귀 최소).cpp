#include <iostream>
#include <cstring>
#include <algorithm>

/*
input
2
10

output
1
3

https://www.acmicpc.net/problem/1463

/* Copyright (C) 2017 by Son */

using namespace std;

int* dy;						// 재귀에서 이미 값이 정해진 부분은 return하고 빠지기 위해서

int recursive_solve(int num)
{
	if (num == 1) {				// 1일 때 더할 값 0 왜냐면 return 들어갈 때 1 더해주므로
		return 0;
	}
	if (dy[num - 1] > 0) {		// 이미 값이 존재하면 return
		return dy[num - 1];
	}
	if (dy[num - 2] == 0) {		// n-1 값이 존재하지 않으면 값 대입
		dy[num - 2] = recursive_solve(num - 1);
	}
	if (num % 3 == 0) {			// 3으로 나누어 떨어질 때 3으로 나눌 지 아니면 -1한 값을 넣을 지(dy[num-2])(빼기 해서 2로 계속 나눠질 수 있으므로)
		return (dy[num - 1] = 1 + min(recursive_solve(num / 3), dy[num - 2]));
	}
	else if(num % 2 == 0){		// 2로 나누어 떨어질 때 2로 나눌지 -1한 값을 넣을 지
		return (dy[num - 1] = 1 + min(recursive_solve(num / 2), dy[num - 2]));
	}
	else {
		return  (dy[num - 1] = 1 + dy[num - 2]);
	}
}

int main() {
	int num;
	int count = 0;

	cin >> num;
	
	dy = new int[num];

	memset(dy, 0, 4 * num);				// 헤더 <cstring> 모든 값 0으로 초기화 (가장 빠름)

	cout << recursive_solve(num) << endl;
	
	delete[] dy;

	return 0;
}