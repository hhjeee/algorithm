class Edge {
    constructor(to, cost) {
        this.to = to;
        this.cost = cost;
    }
}

class PriorityQueue {
    constructor() {
        this.arr = [];
    }
    push(a) {
        this.arr.push(a);
        this.arr.sort((a, b) => a.cost - b.cost); //최소힙
    }
    pop() {
        this.arr.pop();
    }
    front() {
        return this.arr[0];
    }
    empty() {
        return this.arr.length === 0;
    }
}

let dist = []
let edgeList = [];

function dijkstra(n, start){
    dist[start] = 0;

    let pq = new PriorityQueue();
    let visited = new Array(n+1).fill(false);

    pq.push(new Edge(start, 0));

    while(!pq.empty()){
        let cur = pq.front();
        pq.pop();

        if(visited[cur.to]) continue;
        visited[cur.to] = true;

        for(let next of edgeList[cur.to]){
            if(dist[next] > next.cost + cur.cost){
                dist[next] = next.cost + cur.cost;
                pq.push(new Edge(next, dist[next]));
            }
        }
    }
}
function main() {
    const fs = require('fs');
    const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

    const [n, m] = input[0].split(' ').map(Number);

    dist = new Array(n+1).fill(Number.MAX_SAFE_INTEGER);
    adjList = new Array(n+1).fill().map(() => []);

    for(let i=1; i<=m; i++){
        const [u, v, w] = input[i].split(' ').map(Number);

        adjList[u].push(new Edge(v, w));
    }

    const start = Number(input[m+1]);

    dijkstra(n, start);
}
