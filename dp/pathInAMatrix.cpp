#include <bits/stdc++.h>
using namespace std;

int getPathHelper(int** a, int c, int r, int n, int ** dp) {
  // if out of bounds
  if(r < 0 || c < 0 || r >= n || c >= n) {
    dp[r][c] = 0;
    return 0;
  }

  // if row n - 1 reached, final dest reached
  if(r == n - 1) {
    dp[r][c] = a[r][c];
    return dp[r][c];
  }

  // check if state already calculated
  if(dp[r][c] > -1) {
    return dp[r][c];
  }

  // from start point a[r][c], we call on all 3 possible ways, take max of them and add val of start point to that and return
  int way1, way2, way3;
  way1 = getPathHelper(a, c, r + 1, n, dp);
  way2 = getPathHelper(a, c + 1, r + 1, n, dp);
  way3 = getPathHelper(a, c - 1, r + 1, n, dp);

  dp[r][c] = a[r][c] + max(way1, max(way2, way3));
  return dp[r][c];
}

int getPath(int** a, int n) {
  int ** dp = new int*[n];
  for(int i = 0; i < n; i++) {
    dp[i] = new int[n];
    for(int j = 0; j < n; j++) {
      dp[i][j] = -1;
    }
  }

  // we will take all columns of first row as start positions one by one
  int maxSum = INT_MIN;
  for(int i = 0; i < n; i++) {
    maxSum = max(maxSum, getPathHelper(a, i, 0, n, dp));
  }
  return maxSum;
}


int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    int** a = new int*[n];
    for(int i = 0; i < n; i++) {
      a[i] = new int[n];
      for(int j = 0; j < n; j++) {
        cin >> a[i][j];
      }
    }

    cout << getPath(a, n) << endl;
  }
}
