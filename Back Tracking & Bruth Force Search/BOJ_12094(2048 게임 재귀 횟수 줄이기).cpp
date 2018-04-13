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
#include <unordered_map>
#include <unordered_set>

using namespace std;
/*

input
3
2 2 2
4 4 4
8 8 8

output
16

https://www.acmicpc.net/problem/12094
/* Copyright (C) 2018 by Son J.W*/

bool end_f;
int n, maxv;
int arr[20][20];

void solve(int s, int cnt) {
	int i, j, k, t, ind, t_max = 0, temp[20][20];
	if (s == 1) {
		for (i = 0; i < n; i++) {
			// �־��ִ� �ε��� (�̵� ���� �պ��� ä����)
			ind = 0; t = 0;
			for (j = 0; j < n; j++) {
				if (arr[i][j] != 0) {
					// t�� ���� (�Ńx �� �������� ������ �����ϴ� ��
					t = arr[i][j];
					t_max = max(t_max, t);
					arr[i][j] = 0;
					j++;
					break;
				}
			}
			for (; j < n; j++) {
				if (arr[i][j] == 0) {
					continue;
				}
				// ���� ���� 0�̸� ���� �� �־� �ְ� 0����
				if (t == 0) {
					t = arr[i][j];
					t_max = max(t_max, t);
					arr[i][j] = 0;
				}
				// ���� ���� ���ٸ� ���簪 0���� �־��� ��ġ�� ���� ����
				else if (arr[i][j] == t) {
					arr[i][j] = 0;
					// ���� �� �ִ밪 ����
					arr[i][ind] = t + t;
					t_max = max(t_max, t + t);
					ind++; t = 0;
				}
				// �ٸ��� �־��� ���� ���� �� �־��ְ� t �� ����
				else {
					arr[i][ind] = t;
					ind++; t = arr[i][j];
					t_max = max(t_max, t);
					arr[i][j] = 0;
				}
			}
			// ���� �ִ� t���� ���� ���� (0�̾ ��� ����)
			arr[i][ind] = t;
		}
	}
	else if (s == 2) {
		for (i = n - 1; i >= 0; i--) {
			ind = n - 1; t = 0;
			for (j = n - 1; j >= 0; j--) {
				if (arr[i][j] != 0) {
					t = arr[i][j];
					t_max = max(t_max, t);
					arr[i][j] = 0;
					j--;
					break;
				}
			}
			for (; j >= 0; j--) {
				if (arr[i][j] == 0) {
					continue;
				}
				if (t == 0) {
					t = arr[i][j];
					t_max = max(t_max, t);
					arr[i][j] = 0;
				}
				else if (arr[i][j] == t) {
					arr[i][j] = 0;
					arr[i][ind] = t + t;
					t_max = max(t_max, t + t);
					ind--; t = 0;
				}
				else {
					arr[i][ind] = t;
					ind--; t = arr[i][j];
					t_max = max(t_max, t);
					arr[i][j] = 0;
				}
			}
			arr[i][ind] = t;
		}
	}
	else if (s == 3) {
		for (j = 0; j < n; j++) {
			ind = 0; t = 0;
			for (i = 0; i < n; i++) {
				if (arr[i][j] != 0) {
					t = arr[i][j];
					t_max = max(t_max, t);
					arr[i][j] = 0;
					i++;
					break;
				}
			}
			for (; i < n; i++) {
				if (arr[i][j] == 0) {
					continue;
				}
				if (t == 0) {
					t = arr[i][j];
					t_max = max(t_max, t);
					arr[i][j] = 0;
				}
				else if (arr[i][j] == t) {
					arr[i][j] = 0;
					arr[ind][j] = t + t;
					t_max = max(t_max, t + t);
					ind++; t = 0;
				}
				else {
					arr[ind][j] = t;
					ind++; t = arr[i][j];
					t_max = max(t_max, t);
					arr[i][j] = 0;
				}
			}
			arr[ind][j] = t;
		}
	}
	else {
		for (j = n - 1; j >= 0; j--) {
			ind = n - 1; t = 0;
			for (i = n - 1; i >= 0; i--) {
				if (arr[i][j] != 0) {
					t = arr[i][j];
					t_max = max(t_max, t);
					arr[i][j] = 0;
					i--;
					break;
				}
			}
			for (; i >= 0; i--) {
				if (arr[i][j] == 0) {
					continue;
				}
				if (t == 0) {
					t = arr[i][j];
					t_max = max(t_max, t);
					arr[i][j] = 0;
				}
				else if (arr[i][j] == t) {
					arr[i][j] = 0;
					arr[ind][j] = t + t;
					t_max = max(t_max, t + t);
					ind--; t = 0;
				}
				else {
					arr[ind][j] = t;
					ind--; t = arr[i][j];
					t_max = max(t_max, t);
					arr[i][j] = 0;
				}
			}
			arr[ind][j] = t;
		}
	}
	maxv = max(t_max, maxv);
	// cnt�� 10�̸� ���ᰡ �Ǿ����ٰ� flag�� ��
	if (cnt == 10) {
		end_f = 1;
		return;
	}
	// ���ᰡ �Ǿ t_max�� ���� �Ǿ���, ���� t_max���� ������ �Ͽ��� maxv�� ���� ���ϸ� ���̻� ���x
	if ((t_max <= ((maxv)/(pow(2,(10-cnt))))) && end_f){
		return;
	}
	cnt++;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			temp[i][j] = arr[i][j];
		}
	}
	for (i = 1; i <= 4; i++) {
		bool flag = 1;
		// ���� ����� ���� ������ ���� ��
		if (i == s) {
			bool flag = 0;
			// ���⿡ ���� �޸� ó��, �� ���� �������� �����غ��� �޶����� ���� �� return
			if (i == 1) {
				for (k = 0; k < n; k++) {
					t = arr[k][0];
					if (t == 0) {
						break;
					}
					for (j = 1; j < n; j++) {
						if (arr[k][j] == 0) {
							break;
						}
						else if (arr[k][j] == t) {
							flag = 1;
							break;
						}
						else {
							t = arr[k][j];
						}
					}
					if (flag) {
						break;
					}
				}
			}
			else if (i == 2) {
				for (k = n - 1; k >= 0; k--) {
					t = arr[k][n-1];
					if (t == 0) {
						break;
					}
					for (j = n-2; j >= 0; j--) {
						if (arr[k][j] == 0) {
							continue;
						}
						else if (arr[k][j] == t) {
							flag = 1;
							break;
						}
						else {
							t = arr[k][j];
						}
					}
					if (flag) {
						break;
					}
				}
			}
			else if (i == 3) {
				for (j = 0; j < n; j++) {
					t = arr[0][j];
					if (t == 0) {
						break;
					}
					for (k = 1; k < n; k++) {
						if (arr[k][j] == 0) {
							continue;
						}
						else if (arr[k][j] == t) {
							flag = 1;
						}
						else {
							t = arr[k][j];
						}
					}
				}
			}
			else {
				for (j = n - 1; j >= 0; j--) {
					t = arr[n-1][j];
					if (t == 0) {
						break;
					}
					for (k = n-2; k >= 0; k--) {
						if (arr[k][j] == 0) {
							continue;
						}
						else if (arr[k][j] == t) {
							flag = 1;
						}
						else {
							t = arr[k][j];
						}
					}
				}
			}
		}
		if (flag) {
			solve(i, cnt);
			for (k = 0; k < n; k++) {
				for (j = 0; j < n; j++) {
					arr[k][j] = temp[k][j];
				}
			}
		}
		else {
			if (cnt == 10) {
				end_f = 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int i, j, k, temp[20][20];
	cin >> n;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> arr[i][j];
			temp[i][j] = arr[i][j];
			maxv = max(arr[i][j], maxv);
		}
	}
	for (i = 1; i <= 4; i++) {
		solve(i, 1);
		for (k = 0; k < n; k++) {
			for (j = 0; j < n; j++) {
				arr[k][j] = temp[k][j];
			}
		}
	}
	cout << maxv << "\n";
	return 0;
}