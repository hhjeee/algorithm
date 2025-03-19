#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n; // #node
vector<vector<int>> adjList;
vector<int> indegree; // 입력받을때 간선받는 노드의 indegree++;

void topologicalSort() {
  queue<int> q;

  for (int i = 1; i <= n; i++) {
    if (!indegree[i])
      q.push(i);
  }

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (int next : adjList[cur]) {
      indegree[next]--;

      if (indegree[next] == 0)
        q.push(next);
    }

    cout << cur << ' ';
  }
}

int main() {
  int m;
  cin >> n >> m;

  adjList.resize(n + 1);
  indegree.resize(n + 1, 0);

  while (m--) {
    int a, b;
    cin >> a >> b;

    adjList[a].push_back(b);
    indegree[b]++;
  }

  topologicalSort();

  return 0;
}
