#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int leafPointer;
int n; // 값이 있는 리프노드 개수
vector<int> tree;

int find_sum(int a, int b) {
  // 주어진 배열에서 인덱스 a부터 인덱스 b까지의 구간합
  int left = leafPointer + a;
  int right = leafPointer + b;

  int sum = 0;
  while (left <= right) {
    if (left % 2 != 0) {
      sum += tree[left];
      left /= 2;
    }
    if (right % 2 == 0) {
      sum += tree[right];
      right /= 2;
    }

    left /= 2;
    right /= 2;
  }

  return sum;
}
void update(int a, int b) {
  // 주어진 배열에서 a번 인덱스의 값을 b로 바꾸겠다
  int idx = leafPointer + a;

  tree[idx] = b;
  idx /= 2;

  while (idx > 0) {
    tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
    idx /= 2;
  }
}
void init() {
  leafPointer = 1;
  while (leafPointer < n) {
    leafPointer * 2;
  }

  tree.resize(leafPointer * 2);

  for (int i = leafPointer; i < leafPointer * 2; i++) {
    tree[i] = i; // 주어진 값 할당
  }

  for (int i = leafPointer - 1; i > 0; i--) {
    tree[i] =
        tree[i * 2] + tree[i * 2 + 1]; // sum이라 가정, min/max 등등 가능 ..
  }
}
