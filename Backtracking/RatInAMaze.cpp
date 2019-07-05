#include <bits/stdc++.h>
using namespace std;

bool isSafe(int maze[MAX][MAX], int x, int y, int n, int** isVisited) {
  if (x >= 0 && y >= 0 && x < n && y < n && maze[x][y] == 1 && isVisited[x][y] == 0) {
    return true;
  }
  return false;
}

void printPathUtil(int maze[MAX][MAX], int n, int x, int y, vector<string> & v, string curr, int ** isVisited) {
    //cout << x << " " << y << " " << curr << endl;
    if(x == n - 1 && y == n - 1) {
      //cout << "here";
      v.push_back(curr);
      return;
    }

    if(isSafe(maze, x, y, n, isVisited)) {
      isVisited[x][y] = 1;
      // down
      curr.push_back('D');
      printPathUtil(maze, n, x + 1, y, v, curr, isVisited);
      curr.pop_back();
      // up
      curr.push_back('U');
      printPathUtil(maze, n, x - 1, y, v, curr, isVisited);
      curr.pop_back();
      // left
      curr.push_back('L');
      printPathUtil(maze, n, x, y - 1, v, curr, isVisited);
      curr.pop_back();
      // right
      curr.push_back('R');
      printPathUtil(maze, n, x, y + 1, v, curr, isVisited);
      curr.pop_back();
      isVisited[x][y] = 0;
    }
}


vector<string> printPath(int m[MAX][MAX], int n)
{
    vector<string> paths;
    int ** isVisited = new int*[n];
    for(int i = 0; i < n; i++) {
        isVisited[i] = new int[n];
        for(int j = 0; j < n; j++) {
          isVisited[i][j] = 0;
        }
    }
    printPathUtil(m, n, 0, 0, paths, "", isVisited);
    sort(paths.begin(), paths.end());
    return paths;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    int ** maze = new int*[n];
    for(int i = 0; i < n; i++) {
      maze[i] = new int[n];
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        cin >> maze[i][j];
      }
    }
    vector<string> sol = printPath(maze, n);
    cout << sol.size() << endl;
  }
}
