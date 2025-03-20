#include <climits>
#include <iostream>
#include <vector>
using namespace std;

struct edge {
  int from, to, cost;
};

int v, e;
vector<long long int> dist;
vector<edge> edgeList;

bool bellmanFord(int start) {
  dist[start] = 0;

  // v-1번 탐색
  for (int i = 0; i < v - 1; i++) {
    for (edge e : edgeList) {
      // 간선의 시작점이 탐색불가
      if (dist[e.from] == LLONG_MAX)
        continue;

      if (dist[e.to] > dist[e.from] + e.cost) {
        dist[e.to] = dist[e.from] + e.cost;
      }
    }
  }

  // 음의 사이클 검사
  for (edge e : edgeList) {
    if (dist[e.from] == LLONG_MAX)
      continue;

    if (dist[e.to] > dist[e.from] + e.cost) {
      return true;
    }
  }

  return false;
}

int main() {
  cin >> v >> e;

  dist.resize(v + 1, LLONG_MAX);
  edgeList.resize(e);

  for (int i = 0; i < e; i++) {
    cin >> edgeList[i].from >> edgeList[i].to >> edgeList[i].cost;
  }

  int start;
  cin >> start;

  bool haveNegativeCycle = bellmanFord(start);

  return 0;
}
