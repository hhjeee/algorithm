let adjList= [];
let visited = [];

function dfs(cur){
    visited[cur] = true;

    for(let next of adjList[cur]){
        if(!visited[next]){
            dfs(next);
        }
    }
}
function main(){
    const fs = require('fs');
    const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

    const [n, m] = input[0].split(' ').map(Number);

    adjList = new Array(n+1).fill().map(() => [])
    visited = new Array(n+1).fill(false);

    for(let i=1; i<=m; i++){
        const [u, v] = input[i].split(' ').map(Number);
        adjList[u].push(v);
        adjList[v].push(u);
    }

    const start = Number(input[m+1])
    dfs(start);
}
