#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int n, m;
vector<vector<int>> map;
vector<vector<bool>> visited;

void bfs(int start_x, int start_y) {
  queue<pair<int, int>> q;
  q.push({start_x, start_y});

  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int next_x = cur.first + dx[i];
      int next_y = cur.second + dy[i];

      if (next_x >= 0 && next_x < n && next_y >= 0 && next_y <= m &&
          !visited[next_x][next_y] && map[next_x][next_y] == 1) {
        visited[next_x][next_y] = true;
        q.push({next_x, next_y});
      }
    }
  }
}
int main() {
  cin >> n >> m;

  map.resize(n, vector<int>(m));
  visited.resize(n, vector<bool>(m, false));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];
    }
  }

  int start_x, start_y;
  cin >> start_x >> start_y;

  bfs(start_x, start_y);

  return 0;
}
