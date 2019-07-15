#include <bits/stdc++.h>
using namespace std;

// Class for cell data type
// it will contain x and y of the cell of chess board, and distance of cell from start pos
class cell {
public:
  int x, y, dist;
  cell() {}
  cell(int x, int y, int dist) {
    this->x = x;
    this->y = y;
    this->dist = dist;
  }
};

bool isValid(int x, int y, int N) {
  if (x >= 1 && x <= N && y >= 1 && y <= N)
        return true;
    return false;
}

// We will consider the problem as shortes path in an unweighted and undirected graph, and hence can be solved with simple bfs
// next state distance = distance of parent + 1
int minStepsToTarget(int n, pair<int, int> knightPos, pair<int, int> targetPos) {
  // x and y pairs to where a knight can move
  int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
  int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

  queue<cell> q;

  // array to mark cells visited
  bool visited[n+1][n+1];
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      visited[i][j] = false;
    }
  }

  // push start cell into queue and mark visited
  q.push(cell(knightPos.first, knightPos.second, 0));
  visited[knightPos.first][knightPos.second] = true;

  // now do bfs till target not reached
  cell current;
  int x, y;
  while(!q.empty()) {
    current = q.front();
  //  cout << current.x << " " << current.y << endl;
    q.pop();
    // check if this cell is target, if yes return distance
    if(current.x == targetPos.first && current.y == targetPos.second) {
      return current.dist;
    }
    // else, push all 8 positions from this cell into queue(check for validity)
    for(int i = 0; i < 8; i++) {
      x = current.x + dx[i];
      y = current.y + dy[i];
      // check if reachable and not visited
      if(isValid(x, y, n) && !visited[x][y]) {
        // mark visited and push to queue
        visited[x][y] = true;
        q.push(cell(x, y, current.dist + 1));
      }
    }
  }
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    pair<int, int> knightPos;
    pair<int, int> targetPos;
    int x, y;
    cin >> x >> y;
    knightPos.first = x;
    knightPos.second = y;
    int a, b;
    cin >> a >> b;
    targetPos.first = a;
    targetPos.second = b;
    cout << minStepsToTarget(n, knightPos, targetPos) << endl;
  }
}
