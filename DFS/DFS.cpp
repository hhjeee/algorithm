#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adjList;
vector<bool> visited;

void dfs(int cur) {
  visited[cur] = true;

  for (int next : adjList[cur]) {
    if (!visited[next]) {
      dfs(next);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  adjList.resize(n + 1);
  visited.resize(n + 1, false);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }

  int start;
  cin >> start;

  dfs(start);

  return 0;
}
