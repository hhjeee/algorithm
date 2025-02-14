#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct edge {
	int from;
	int to;
	int cost;
};

int v, e; 
vector<edge> edgeList;
vector<long long int> dist(v + 1, LONG_MAX);

bool BellmanFord(int start) {
	dist[start] = 0;

	//v-1번 탐색
	for (int i = 0; i < v - 1; i++) {
		for (edge e : edgeList) {
			//간선의 시작점이 탐색불가
			if (dist[e.from] == LONG_MAX) continue;

			if (dist[e.to] > dist[e.from] + dist[e.cost])
				dist[e.to] = dist[e.from] + dist[e.cost];
		}
	}

	//음의 사이클 검사
	bool negativeCycle = false;

	for (edge e : edgeList) {
		if (dist[e.from] == LONG_MAX) continue;

		if (dist[e.to] > dist[e.from] + dist[e.cost]) {
			negativeCycle = true;
			break;
		}
	}

	return negativeCycle;
}
