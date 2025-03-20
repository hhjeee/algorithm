class Queue {
    constructor(){
        this.arr = [];
    }
    push(a){
        this.arr.push(a);
    }
    pop(){
        this.arr.shift();
    }
    front() {
        return this.arr[0];
    }
    empty(){
        return this.arr.length === 0;
    }
}

let dx = [0, 1, 0, -1];
let dy = [1, 0, -1, 0];

let map = [];
let visited = [];

function bfs(n, m, start_x, start_y){
    let q = new Queue();
    q.push({x: start_x, y: start_y});

    while(!q.empty()){
        let cur = q.front();
        q.pop();

        for(let i=0; i<4; i++){
            let next_x = cur.x + dx[i];
            let next_y = cur.y + dy[i];

            if(next_x >= 0 && next_x < n && next_y >=0 && next_y < m && !visited[next_x][next_y] && map[next_x][next_y]){
                visited[next_x][next_y] = true;
                q.push({x: next_x, y: next_y});
            }
        }
    }
}

function main() {
    const fs = require('fs');
    const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

    const [n, m] = input[0].split(' ').map(Number);

    map = new Array(n).fill().map(() => new Array(m));
    visited = new Array(n).fill().map(() => new Array(m).fill(false));

    for(let i=0; i<n; i++){
        map[i] = input[i + 1].split(' ').map(Number);
    }

    const [start_x, start_y] = input[n+1].split(' ').map(Number);

    bfs(n, m, start_x, start_y);
}
