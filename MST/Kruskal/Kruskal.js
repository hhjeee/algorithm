class Edge {
  constructor(from, to, cost) {
    this.from = from;
    this.to = to;
    this.cost = cost;
  }
}

let parent = [];
let edgeList = [];

function init(n) {
  for (let i = 1; i <= n; i++) {
    parent[i] = i;
  }
}
function union(a, b) {
  let aRoot = find(a);
  let bRoot = find(b);

  if (aRoot !== bRoot) parent[bRoot] = aRoot;
}
function find(a) {
  if (parent[a] === a) return a;
  return (parent[a] = find(parent[a]));
}

function kruskal(n, m) {
  init();

  let sum = 0;
  let edgeCount = 0;

  for (let i = 0; i < m; i++) {
    if (find(edgeList[i].from) != find(edgeList[i].to)) {
      union(edgeList[i].from, edgeList[i].to);

      sum += edgeList[i].cost;
      edgeCount++;

      if (edgeCount == n - 1) return sum;
    }
  }

  return -1;
}

function main() {
  const fs = require('fs');
  const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

  const [n, m] = input[0].split(' ').map(Number);

  parent = new Array(n + 1);
  edgeList = new Array(m).fill().map(() => new Edge(0, 0, 0));

  for (let i = 0; i < m; i++) {
    const [from, to, cost] = input[i + 1].split(' ').map(Number);
    edgeList[i] = new Edge(from, to, cost);
  }

  edgeList.sort((a, b) => a.cost - b.cost);

  kruskal(n, m);
}
