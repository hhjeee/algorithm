class Edge {
    constructor(from, to, cost){
        this.from = from;
        this.to = to;
        this.cost = cost;
    }
}

let dist = [];
let edgeList = [];

function bellmanFord(v, start){
    dist[start] = 0;

    for(let i=0; i<v-1; i++){
        for(let e of edgeList){
            if(dist[e.from] === Number.MAX_SAFE_INTEGER) continue;

            if(dist[e.to] > dist[e.from] + e.cost)
                dist[e.to] = dist[e.from] + e.cost;
        }
    }

    for(let e of edgeList){
        if(dist[e.from] === Number.MAX_SAFE_INTEGER) continue;

        if(dist[e.to] > dist[e.from] + e.cost)
            return true;
    }

    return false;
}

function main() {
    const fs = require('fs');
    const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

    const [v, e] = input[0].split(' ').map(Number);

    dist = new Array(v+1).fill(Number.MAX_SAFE_INTEGER);
    edgeList = new Array(e).fill().map(() => new Edge(0,0,0));

    for(let i=0; i<e; i++){
        const [from, to, cost] = input[i+1].split(' ').map(Number);
        edgeList[i] = new Edge(from, to, cost);
    }

    const start = Number(input[e+1]);
    let haveNegativeCycle = bellmanFord(v, start);
}
