#include <bits/stdc++.h>
using namespace std;

// We can move right or left we have to go from top left to bottom right
int getNumPaths(int m, int n, int currRow, int currCol) {
  // Base case : if bottom right reached
  if (currRow == m - 1 && currCol == n - 1) {
    return 1;
  }

  // Call on right
  int x = 0, y = 0;
  if(currCol < n - 1) {
    x = getNumPaths(m, n, currRow, currCol + 1);
  }
  // Call on down
  if(currRow < m - 1) {
    y = getNumPaths(m, n, currRow + 1, currCol);
  }

  return x + y;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int m, n;
    cin >> m >> n;
    cout << getNumPaths(m, n, 0, 0) << endl;
  }
}
