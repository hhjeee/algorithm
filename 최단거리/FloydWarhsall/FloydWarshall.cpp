#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int n, m; // #node, #edge
vector<vector<int>> dist;

void FloydWarshall() {
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i == k || k == i)
          continue;
        if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
          continue;

        if (dist[i][j] > dist[i][k] + dist[k][j])
          dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }
}

int main() {
  cin >> n >> m;

  dist.assign(n + 1, vector<int>(n + 1, INT_MAX));

  for (int i = 1; i <= n; i++)
    dist[i][i] = 0;

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    dist[u][v] = w;
  }

  FloydWarshall();

  return 0;
}
