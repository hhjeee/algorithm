#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct edge {
	int to;
	int cost;
};
struct compare {
	bool operator() (edge a, edge b) {
		return a.cost > b.cost;
	}
};

int n; // #node
vector<int> dist(n + 1, INT_MAX);
vector<vector<edge>> adjList(n + 1);

void dijkstra(int start) {
	dist[start] = 0;

	priority_queue<edge, vector<edge>, compare> pq;
	vector<bool> visited(n + 1, false);

	pq.push({ start, 0 });

	while (!pq.empty()) {
		edge cur = pq.top();
		pq.pop();

		if (!visited[cur.to]) continue;
		visited[cur.to] = true;

		for (edge next : adjList[cur.to]) {
			if (dist[next.to] > cur.cost + next.cost) {
				dist[next.to] = cur.cost + next.cost;
				pq.push({ next.to, dist[next.to] });
			}
		}
	}

}
