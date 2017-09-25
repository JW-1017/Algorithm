#include <iostream>
#include <queue>
#include <map>
#include <stack>
#include <vector>

#define MAX_VALUE -99999999999

/*
input:
5
8
1 2 2
1 3 3
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
1 5

output:
4

https://www.acmicpc.net/problem/1916
/* Copyright (C) 2017 by Son */

using namespace std;

class Vertex {
public:
	int index;
	long long dist;
	int post = 0;
	Vertex(int index, long long dist, int post) :index(index), dist(dist), post(post) {
	}
	Vertex(int index) :index(index) {
		dist = MAX_VALUE;
	}
	void setDist(long long d) {
		dist = d;
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
	int n = 0;
	vector<long long> dist;
	vector<Vertex> vt;
	vector<vector<pair<int, int> > > adj;
	priority_queue<Vertex> pq;
	map<int, pair<long long, int> > m;

	void setStart(int index) {
		vt[index - 1].setDist(0);
		vt[index - 1].post = index;
	}
	/*
	void addVertex(int index, int sig) {
		pq.push(Vertex(index, 0, index));
		this->dist.push_back(0);
		n++;
		adj.resize(n + 1);
	}*/
	void addVertex(int index) {
		vt.push_back(Vertex(index));
		this->dist.push_back(-1 * MAX_VALUE);
		n++;
		adj.resize(n);
	}
	void addAdj(int u, int v, int w) {
		adj[u - 1].push_back(make_pair(v, w));
	}
	void dijkstra(int s) {
		dist[s - 1] = 0;
		setStart(s);
		for (int i = 0; i < n; i++) {
			pq.push(vt[i]);
		}
		m.insert(make_pair(s, make_pair(0, -1)));
		while (!pq.empty()) {
			int index = pq.top().index - 1;
			long long cost = -1 * pq.top().dist;
			pq.pop();
			if (dist[index] < cost) {
				continue;
			}
			int adj_size = adj[index].size();
			for (int i = 0; i < adj_size; i++) {
				int n = adj[index][i].first;
				int v = adj[index][i].second;
				if (dist[n - 1] > dist[index] + v) {
					dist[n - 1] = dist[index] + v;
					Vertex newVt = Vertex(n, -dist[n - 1], index + 1);
					pq.push(newVt);
					m[n] = make_pair(dist[n - 1], index + 1);
				}
			}
		}
	}
	void printIndexMinDis(int index) {
		//인덱스별 최소거리
		if (dist[index - 1] != -1 * MAX_VALUE) {
			cout << dist[index - 1] << "\n";
		}
		else {
			cout << "INF\n";
		}
	}
	void printPostAndMinDis(int index) {
		//printf("인덱스 - 최단 경로 - 이전 정점\n");
		//printf("%d - %d - %d\n", index, m[index].first, m[index].second);
	}
	void printMinRoute(int index) {
		//printf(인덱스까지 경로 : ", index);
		/*
		if (dist[index-1] != -1*MAX_VALUE) {
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
		}*/
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	int i, n, m, s, e;
	int u, v, w;
	cin >> n >> m;
	Graph gp;
	for (i = 1; i <= n; i++) {
		gp.addVertex(i);
	}
	for (i = 0; i < m; i++) {
		cin >> u >> v >> w;
		gp.addAdj(u, v, w);
	}
	cin >> s >> e;
	gp.dijkstra(s);
	gp.printIndexMinDis(e);
	return 0;
}