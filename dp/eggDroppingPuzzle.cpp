#include <bits/stdc++.h>
using namespace std;

// we solve the problem recursively
// we test for each floor from 1 to k, and return the minimum trials needed in worst case
// at xth floor there are two options, if egg breaks problem reduces to n-1 eggs and x - 1 floors
// if egg doesnt break, problem reduces to n eggs and k - x floors

int minTrialsForEggDropping(int n, int k, int ** dp) {

  // if 0 or 1 floor, answer is 0 or 1
  if(k == 0 || k == 1) {
    dp[n][k] = k;
    return k;
  }

  // if 1 egg, we need to drop at each floor once
  if(n == 1) {
    dp[n][k] = k;
    return k;
  }

  // check if state already calculated
  if(dp[n][k] > -1) {
    return dp[n][k];
  }

  int ans = INT_MAX;
  // start dropping from floors 1 to k
  for(int x = 1; x <= k; x++) {
    ans = min(ans, max(minTrialsForEggDropping(n - 1, x - 1, dp), minTrialsForEggDropping(n, k - x, dp)));
  }

  dp[n][k] = ans + 1;
  return dp[n][k];
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n, k;
    cin >> n >> k;
    // init a 2d dp array
    int ** dp = new int*[n + 1];
    for(int i = 0; i <= n; i++) {
      dp[i] = new int[k + 1];
      for(int j = 0; j <= k; j++) {
        dp[i][j] = -1;
      }
    }
    cout << minTrialsForEggDropping(n, k, dp) << endl;
  }
}
