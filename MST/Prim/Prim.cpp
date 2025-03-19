#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct edge {
  int to, cost;
};
struct compare {
  bool operator()(edge a, edge b) { return a.cost > b.cost; }
};

int n, m; // #node, #edge
vector<vector<edge>> adjList;

int prim() {
  int sum = 0;
  int selectedNodeCount = 0;

  priority_queue<edge, vector<edge>, compare> pq;
  pq.push({1, 0}); // 시작점이 1, 1으로 가는 cost가 0

  vector<bool> selected(n + 1, false);

  while (!pq.empty()) {
    edge cur = pq.top();
    pq.pop();

    if (selected[cur.to])
      continue;

    selected[cur.to] = true;
    sum += cur.cost;
    selectedNodeCount++;

    // 모든 정점이 선택되면 종료
    if (selectedNodeCount == n)
      return sum;

    for (edge next : adjList[cur.to]) {
      if (!selected[next.to])
        pq.push(next);
    }
  }

  return -1;
}

int main() {
  cin >> n >> m;
  adjList.resize(n + 1);

  for (int i = 0; i < m; i++) {
    int u, v, cost;
    cin >> u >> v >> cost;
    adjList[u].push_back({v, cost});
    adjList[v].push_back({u, cost});
  }

  prim();

  return 0;
}
