#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> parent(n);

void init() {
	for (int i = 1; i <= n; i++) parent[i] = i;
}
void uni_on(int a, int b) {
	int aRoot = find(a);
	int bRoot = find(b);

	if (aRoot != bRoot)
		parent[bRoot] = aRoot;
}
int find(int a) {
	if (parent[a] == a) return a;
	else return parent[a] = find(parent[a]);
}

