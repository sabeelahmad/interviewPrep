#include <bits/stdc++.h>
using namespace std;

long long findWays(int m, int n, int x) {
  // making a dp table of n*x
  long long dp[n + 1][x + 1];
  memset(dp, 0, sizeof(dp));

  // concept is that we try to make all sum from 1 to m from current dice and the rest from other dice recursively
  // using this we will build our dp table

  // if we have only one dice, there is only one way to make sum from x, if x <= m
  for(int j = 1; j <= x && j <= m; j++) {
    dp[1][j] = 1;
  }

  // filling rest of table using the recursive relation
  // i : num dice
  // j : sum
  for(int i = 2; i <= n; i++) {
    for(int j = 1; j <= x; j++) {
      // we check to make sum j from 1 to m
      for(int k = 1; k <= m && k < j; k++) {
        dp[i][j] += dp[i - 1][j - k];
      }
    }
  }

  return dp[n][x];
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int m, n, x;
    cin >> m >> n >> x;
    cout << findWays(m, n, x) << endl;
  }
}
