class Queue {
  constructor() {
    this.arr = [];
  }
  push(a) {
    this.arr.push(a);
  }
  pop() {
    this.arr.shift();
  }
  front() {
    return this.arr[0];
  }
  empty() {
    return this.arr.length === 0;
  }
}

let indegree = [];
let adjList = [];

function topologicalSort(n) {
  const q = new Queue();

  for (let i = 1; i <= n; i++) {
    if (!indegree[i]) q.push(i);
  }

  while (!q.empty()) {
    let cur = q.front();
    q.pop();

    for (let next of adjList[cur]) {
      indegree[next]--;

      if (!indegree[next]) q.push(next);
    }
  }
}

function main() {
  const fs = require('fs');
  const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

  const [n, m] = input[0].split(' ').map(Number);

  indegree = new Array(n + 1).fill(0);
  adjList = new Array(n + 1).fill().map(() => []);

  for (let i = 1; i <= m; i++) {
    let [a, b] = input[i].split(' ').map(Number);

    adjList[a].push(b);
    indegree[b]++;
  }

  topologicalSort(n);
}
