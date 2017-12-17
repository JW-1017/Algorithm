#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include <vector>

#define MAX_VALUE -2147483647			// 우선순위 큐 사용을 위해(디폴트로 큰값을 뺌, 빠른 속도를 위해 compare를 오버 로딩x)

using namespace std;

/*
input:
5 6
1
5 1 1
1 2 2
1 3 3
2 3 4
2 4 5
3 4 6

output:
0
2
3
7
INF

https://www.acmicpc.net/problem/1753
/* Copyright (C) 2017 by Son */

// 인덱스 무조건 1부터
class Vertex {
public:
	int index;
	int dist;
	Vertex() {}
	Vertex(int index, int dist) :index(index), dist(dist) {
	}
	Vertex(int index) :index(index) {
		dist = MAX_VALUE;
	}
	bool operator >(const Vertex& v) const {
		return dist > v.dist;
	}
	bool operator <(const Vertex& v) const {
		return dist < v.dist;
	}
};
class Graph {
public:
	int num = 0;
	int* dist;
	vector<Vertex> vt;
	vector<pair<int, int>>* adj;
	priority_queue<Vertex> pq;
	//map<int, pair<int, int>> m;			

	void addVertex(int index) {
		vt.push_back(Vertex(index));
		num++;
	}
	void setAdj() {
		adj = new vector<pair<int, int>>[num];
	}
	void addAdj(int u, int v, int w) {
		adj[u - 1].push_back(make_pair(v, w));
	}
	void dijkstra(int s) {
		dist = new int[num];
		for (int i = 0; i < num; i++) {
			dist[i] = -1 * MAX_VALUE;
		}
		dist[s] = 0;
		vt[s].dist = 0;
		pq.push(vt[s]);
		//m[s+1] = make_pair(0, -1);

		while (!pq.empty()) {
			int index = pq.top().index - 1;
			int temp = dist[index];
			int cost = -1 * pq.top().dist;
			pq.pop();
			if (temp < cost) {
				continue;
			}
			int size = adj[index].size();
			for (int i = 0; i < size; i++) {
				int n = adj[index][i].first;
				int v = adj[index][i].second + temp;
				if (dist[n - 1] > v) {
					dist[n - 1] = v;
					pq.push(Vertex(n, -v));
					//m[n] = make_pair(v, index+1);
				}
			}
		}
	}
	void printIndexMinDis(int index) {
		//인덱스별 최소거리
		if (dist[index] != -1 * MAX_VALUE) {
			cout << dist[index] << "\n";
		}
		else {
			cout << "INF\n";
		}
	}
	/*
	void printMinRoute(int index) {
	if (dist[index] != -1 * MAX_VALUE) {
	stack<int> st;
	int next = m[index].second;
	while (next != -1) {
	st.push(next);
	next = m[next].second;
	}
	while (!st.empty()) {
	printf("%d - ", st.top());
	st.pop();
	}
	printf("%d\n", index);
	}
	}*/
};
int main()
{
	std::ios::sync_with_stdio(false);
	int i, n, m, s;
	int u, v, w;
	cin >> n >> m;
	cin >> s;
	Graph gp;

	for (i = 1; i <= n; i++) {
		gp.addVertex(i);
	}
	gp.setAdj();
	for (i = 0; i < m; i++) {
		cin >> u >> v >> w;
		gp.addAdj(u, v, w);
	}
	gp.dijkstra(s - 1);
	for (i = 0; i < n; i++) {
		gp.printIndexMinDis(i);
	}

	return 0;
}