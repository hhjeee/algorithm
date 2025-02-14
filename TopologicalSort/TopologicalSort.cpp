#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n; // #node
vector<vector<int>> adjList(n + 1);
vector<int> indegree(n + 1, 0); //입력받을때 간선받는 노드의 indegree++;

void topologicalSort() {
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (!indegree[i]) q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : adjList[cur]) {
			indegree[next]--;

			if (indegree[next] == 0) q.push(next);
		}

		cout << cur << ' ';
	}
}
