#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int root = 1;
int n; // #node
const int LOG = 17;
// 최대 노드(N) 수 보다 큰 가장 작은 2^n 값을 선택
// c.f. 2^15 < N=50000 < 2^16
// c.f. 2^16 < N=100000 < 2^17

vector<vector<int>> adjList(n+1);
vector<int> depth(n + 1);
vector<vector<int>> parent(LOG+1, vector<int>(n + 1));

void bfs() {
	queue<int> q;
	vector<bool> visited(n+1, false);

	q.push(root);
	visited[root] = true;
	depth[root] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : adjList[cur]) {
			if (!visited[next]) {
				depth[next] = depth[cur] + 1;
				parent[0][cur] = next;

				visited[next] = true;
				q.push(next);
			}
		}
	}
}
void find_ancestors() {
	for (int i = 1; i <= LOG; i++) {
		for (int j = 1; j <= n; j++) {
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
		}
	}
}
int find_LCA(int a, int b) {
	if (depth[a] > depth[b]) {
		int tmp = a;
		a = b;
		b = tmp;
	}

	for (int k = LOG; k >= 0; k--) {
		if ((depth[b] - depth[a]) >= (1 << k))
			b = parent[k][b];
	}

	if (a == b) return a;

	for (int k = LOG; k >= 0; k--) {
		if (parent[k][a] != parent[k][b]) {
			a = parent[k][a];
			b = parent[k][b];
		}
	}

	return parent[0][a];
}
