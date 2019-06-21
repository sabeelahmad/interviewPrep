/*
You are given an array A of size N. The array contains integers and is of even length. 4
The elements of the array represent N coin of values V1, V2, ....Vn. You play against an opponent in an alternating way.

In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin.
You need to determine the maximum possible amouint of money you can win if you go first.
*/

#include <bits/stdc++.h>
using namespace std;

// we call on both coins, once we pick up first, then second, and then call recursion on rest
// but the user is also playing optimally, so when we pick up a coin on our odd turns we get the best of (i, j)
// on even turn we get min(i, j) because on previous turn opponent has picked the best coin

int optimalStrategyHelper(int *a, int i, int j, int ** dp) {
  if(i == j) {
    // only one coin remaing
    dp[i][j] = a[i];
    return a[i];
  }
  if(j == i + 1) {
    // two coins, pick max of two
    dp[i][j] = max(a[i], a[j]);
    return dp[i][j];
  }

  if(dp[i][j] > -1) {
    return dp[i][j];
  }

  dp[i][j] = max(
    // pick first coin, other will pick best, so we will pick min of the next turn options
    a[i] + min(optimalStrategyHelper(a, i + 2, j, dp), optimalStrategyHelper(a, i + 1, j - 1, dp)),
    // pick last coin, other will pick best, so we will pick min of the next turn options
    a[j] + min(optimalStrategyHelper(a, i + 1, j - 1, dp), optimalStrategyHelper(a, i, j - 2, dp))
  );

  return dp[i][j];
}

int optimalStrategy(int* a, int n) {
  int ** dp = new int*[n];
  for(int i = 0; i < n; i++) {
    dp[i] = new int[n];
    for(int j = 0; j < n; j++) {
      dp[i][j] = -1;
    }
  }
  return optimalStrategyHelper(a, 0, n - 1, dp);
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    cout << optimalStrategy(a, n) << endl;
  }
}
