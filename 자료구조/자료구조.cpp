#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>

using namespace std;

int main() {
  // stack
  stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.top(); // 3
  s.pop();
  s.top(); // 2

  // queue
  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.front(); // 1
  q.pop();
  q.front(); // 2

  // deque
  deque<int> dq;
  dq.push_back(10);
  dq.push_front(20);
  dq.push_back(30);
  dq.front(); // 20
  dq.back();  // 30
  dq.pop_front();
  dq.front(); // 10

  // priority_queue - 최대 힙
  priority_queue<int> pq;
  pq.push(50);
  pq.push(20);
  pq.push(40);
  pq.top(); // 50

  // priority_queue - 최소 힙
  priority_queue<int, vector<int>, greater<int>> min_pq;
  min_pq.push(50);
  min_pq.push(20);
  min_pq.push(40);
  min_pq.top(); // 20

  // hash map
  unordered_map<string, int> umap;
  umap["banana"] = 20;
  umap["orange"] = 30;
  umap["apple"] = 10;

  for (auto it : umap) {
    cout << it.first << " " << it.second << endl;
  }
  // banana 20
  // orange 30
  // apple 10

  // map
  map<string, int> map;
  map["banana"] = 20;
  map["apple"] = 10;
  map["orange"] = 30;

  for (auto it : map) {
    cout << it.first << " " << it.second << endl;
  }

  // apple 10
  // banana 20
  // orange 30

  // set
  set<int> set;
  set.insert(100);
  set.insert(50);
  set.insert(150);
  set.insert(50); // 중복 추가

  for (auto it : set) {
    cout << it << " ";
  }
  // 50 100 150

  return 0;
}
