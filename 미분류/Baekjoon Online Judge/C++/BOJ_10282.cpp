#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include <vector>

#define MAX_VALUE -2147483647			// �켱���� ť ����� ����(����Ʈ�� ū���� ��, ���� �ӵ��� ���� compare�� ���� �ε�x)

using namespace std;

/*
input:
2
3 2 2
2 1 5
3 2 5
3 3 1
2 1 2
3 1 8
3 2 4

output:
2 5
3 6

https://www.acmicpc.net/problem/10282
/* Copyright (C) 2017 by Son */

// �ε��� ������ 1����
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
	void printIndexMinDis() {
		int count = 0;
		int max = MAX_VALUE;

		for (int i = 0; i < num; i++) {
			if (dist[i] != -1 * MAX_VALUE) {
				count++;
				if (max < dist[i]) {
					max = dist[i];
				}
			}
		}
		cout << count << " " << max << "\n";
	}
	void new_dijkstra() {
		delete[] dist;
		vt.clear();
		delete[] adj;
		num = 0;
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
	int i, j, n, m, s, num;
	int u, v, w;
	cin >> num;
	for (j = 0; j < num; j++) {
		cin >> n >> m >> s;
		Graph gp;
		for (i = 1; i <= n; i++) {
			gp.addVertex(i);		// �ε��� �״��
		}
		gp.setAdj();				// �ʼ�
		for (i = 0; i < m; i++) {
			cin >> u >> v >> w;
			gp.addAdj(v, u, w);		// �ε��� �״��
		}
		gp.dijkstra(s-1);
		gp.printIndexMinDis();
		gp.new_dijkstra();
	}
	return 0;
}