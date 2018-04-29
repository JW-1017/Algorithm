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
#include <deque>
#include <stack>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>

using namespace std;
/*
input
4 5
2 1
3 1
4 0
1 1
5 0

output
2 4
1 4
3 4
3 1
3 2

http://codeforces.com/problemset/problem/605/B
/* Copyright (C) 2018 by Son J.W*/

typedef long long ll;
typedef pair<int, int> pa;
typedef pair<int, pair<int, int>> ppa;

class pb {
public:
	// weight, 포함여부, index
	int first;
	int second;
	int index;

	pb() {}
	pb(int a, int b, int index) {
		this->first = a;
		this->second = b;
		this->index = index;
	}
	// 정렬 했을 때 weight가 작고, 포함여부는 1인 pair가 앞에 오게
	bool operator <(const pb& k) const{
		if (this->first < k.first) {
			return 1;
		}
		else if (this->first > k.first) {
			return 0;
		}
		else {
			if (this->second > k.second) {
				return 1;
			}
			else {
				return 0;
			}
		}
	}
};

// 결과 저장용
pa res[100000];
vector<pb> v;

int main() {
	bool t;
	int i, n, m, a, b = 0, c, temp = 1;
	cin >> n >> m;
	priority_queue<pb> pq;
	for (i = 0; i < m; i++) {
		cin >> a >> t;
		if (t) {
			b++;
		}
		v.push_back(pb(a, t, i));
	}
	if (b > n - 1) {
		cout << "-1\n";
		return 0;
	}
	sort(v.begin(), v.end());
	a = 1;
	b = 1;
	c = 3;
	for (i = 0; i < m; i++) {
		pb t = v[i];
		if (t.second) {
			// 포함 되어 있다면 1-2 2-3 이런식으로 연결 해둠
			res[t.index] = pa(a, a + 1);
			a++;
		}
		else {
			// 현재 끝 점까지로 만들수 있는 조합을 만듬 ex) a == 4이면
			// 1, 3, 2, 4 (1,2 2,3 은 안됨)
			// 끝 점 넘어가 버린면 종료
			if (c > a) {
				cout << "-1\n";
				return 0;
			}
			res[t.index] = pa(b, c);
			b++;
			// 조합수는 앞에수가 뒷 수 보다 무조건 작게
			// 커버리면 c값 조절로 값 변경
			if (b >= c-1) {
				b = 1;
				c++;
			}
		}
	}
	for (i = 0; i < m; i++) {
		cout << res[i].first << " " << res[i].second << "\n";
	}
	return 0;
}