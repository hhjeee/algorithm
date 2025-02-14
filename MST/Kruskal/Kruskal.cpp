#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct edge {
	int from;
	int to;
	int cost;
};
bool compare (edge a, edge b) {
	return a.cost < b.cost;
};

int n; // #node
vector<int> parent(n + 1);
vector<edge> edgeList; //sort(edgeList.begin(), edgeList.end(), compare);

void init() {
	for (int i = 1; i <= n; i++) parent[i] = i;
}
int find(int a) {
	if (parent[a] == a) return a;
	else return parent[a] = find(parent[a]);
}
void uni_on(int a, int b) {
	int aRoot = find(a);
	int bRoot = find(b);

	if (aRoot != bRoot)
		parent[bRoot] = aRoot;
}

int kruskal() {
	int sum = 0;
	int edgeCount = 0;

	for (int i = 0; i < edgeList.size(); i++) {
		if (find(edgeList[i].from) != find(edgeList[i].to)) {
			uni_on(edgeList[i].from, edgeList[i].to);

			sum += edgeList[i].cost;
			edgeCount++;
		}

		if (edgeCount == n - 1) break;
	}

	return sum;
}
