
let dist = [];

function FloydWarshall(n){
    for(let k=1; k<=n; k++){
        for(let i=1; i<=n; i++){
            for(let j=1; j<=n; j++){
                if(i === k || k === j) continue;

                if(dist[i][k] === Number.MAX_SAFE_INTEGER || dist[k][j] === Number.MAX_SAFE_INTEGER) continue;

                if(dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}
function main() {
    const fs = require('fs');
    const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

    const [n, m] = input[0].split(' ').map(Number);

    dist = new Array(n+1).fill().map(() => new Array(n+1).fill(Number.MAX_SAFE_INTEGER));

    for(let i=1; i<=n; i++){
        dist[i][i] = 0;
    }

    for(let i=1; i<=m; i++){
        const [u, v, w] = input[i].split(' ').map(Number);
        dist[u][v] = w;
    }

    FloydWarshall();
}
