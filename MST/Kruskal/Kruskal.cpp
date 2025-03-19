#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct edge {
  int from, to, cost;
};
bool compare(edge a, edge b) { return a.cost < b.cost; }

int n, m; // #node, #edge
vector<int> parent;
vector<edge> edgeList;

void init() {
  for (int i = 1; i <= n; i++)
    parent[i] = i;
}
int find(int a) {
  if (parent[a] == a)
    return a;
  return parent[a] = find(parent[a]);
}
void uni_on(int a, int b) {
  int aRoot = find(a);
  int bRoot = find(b);
  
  if (aRoot != bRoot)
    parent[bRoot] = aRoot;
}

int kruskal() {
  init();

  int sum = 0, edgeCount = 0;

  for (int i = 0; i < edgeList.size(); i++) {
    if (find(edgeList[i].from) != find(edgeList[i].to)) {
      uni_on(edgeList[i].from, edgeList[i].to);

      sum += edgeList[i].cost;
      edgeCount++;
    }

    if (edgeCount == n - 1)
      return sum;
  }

  return -1; // 만들기 실패(연결 불가한 노드 존재)
}

int main() {
  cin >> n >> m;

  parent.resize(n + 1);
  edgeList.resize(m);

  for (int i = 0; i < m; i++) {
    cin >> edgeList[i].from >> edgeList[i].to >> edgeList[i].cost;
  }

  sort(edgeList.begin(), edgeList.end(), compare);

  kruskal();

  return 0;
}
