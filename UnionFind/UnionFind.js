let parent = [];

function init(n) {
    parent = new Array(n+1);
    for (let i=1; i<=n; i++) parent[i] = i;
}
function union(a, b) {
    let aRoot = find(a);
    let bRoot = find(b);

    if(aRoot !== bRoot)
        parent[bRoot] = aRoot;
}
function find(a) {
    if(parent[a] === a) return a;
    return parent[a] = find(parent[a]);
}
