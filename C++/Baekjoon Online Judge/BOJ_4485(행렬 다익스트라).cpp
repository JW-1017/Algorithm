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
3
5 5 4
3 9 1
3 2 7
5
3 7 2 0 1
2 8 0 9 1
1 2 1 8 1
9 8 9 2 0
3 6 5 1 5
7
9 0 5 1 1 5 3
4 1 2 1 6 5 3
0 7 6 1 6 8 5
1 1 7 8 3 2 3
9 4 0 7 6 4 1
5 8 3 2 4 8 3
7 4 8 4 8 3 4
0

output:
Problem 1: 20
Problem 2: 19
Problem 3: 36

https://www.acmicpc.net/problem/4485
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
	void addAdj(int u, int v, int w) {			// u로 부터 v까지 w cost
		adj[u-1].push_back(make_pair(v, w));
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
				if (dist[n-1] > v) {
					dist[n-1] = v;
					pq.push(Vertex(n, -v));
					//m[n] = make_pair(v, index+1);
				}
			}
		}
	}
	void new_dijkstra() {
		delete[] dist;
		vt.clear();
		delete[] adj;
		num = 0;
	}
	int printIndexMinDis(int index) {
		//인덱스별 최소거리
		return dist[index];
		/*
		if (dist[index] != -1 * MAX_VALUE) {
			cout << dist[index] << "\n";
		}
		else {
			cout << "INF\n";
		}
		*/
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
	
	int i, j, num, result, temp;
	int index, count = 0;
	Graph gp;
	
	while (1) {
		count++;
		cin >> num;
		if (num == 0) {
			break;
		}
		for (i = 1; i <= (num*num); i++) {
			gp.addVertex(i);
		}
		gp.setAdj();
		for (i = 1; i <= num; i++) {
			for (j = 1; j <= num; j++) {
				if (i == 1) {
					if (j == 1) {
						cin >> result;
					}
					else {
						cin >> temp;
						gp.addAdj(j - 1, j, temp);
						gp.addAdj(j + num, j, temp);			// 밑에서 올라올수도
						if (j != num) {
							gp.addAdj(j + 1, j, temp);			// 오른쪽에서 올수도
						}
					}
				}
				else if (j == 1) {
					index = (i - 1) * num + j;
					cin >> temp;
					gp.addAdj(index - num, index, temp);
					gp.addAdj(index + 1, index, temp);			// 오른쪽에서 올수도
				}
				else {
					cin >> temp;
					index = (i - 1) * num + j;
					gp.addAdj(index-1, index, temp);
					gp.addAdj(index - num, index, temp);
					if (i != num && j != num) {
						gp.addAdj(index + num, index, temp);	// 밑에서 올라올수도
					}
					if (j != num) {
						gp.addAdj(index + 1, index, temp);		// 오른쪽에서 올수도
					}
				}
			}
		}
		gp.dijkstra(0);
		cout << "Problem "  << count << ": "<< result + gp.printIndexMinDis(num*num - 1) << "\n";
		gp.new_dijkstra();
	}

	return 0;
}