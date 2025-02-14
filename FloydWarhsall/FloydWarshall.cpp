#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n; // #node
vector<vector<int>> dist(n + 1, vector<int>(n + 1, INT_MAX));

void init() {
	for (int i = 1; i <= n; i++) {
		dist[i][i] = 0;
	}

	// a -> b 일때의 cost(c) 목록 받아서
	// dist[a][b] = c;
}
void FloydWarshall() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == k || k == i) continue;
				if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;

				if (dist[i][j] > dist[i][k] + dist[k][i])
					dist[i][j] = dist[i][k] + dist[k][i];
			}
		}
	}
}
