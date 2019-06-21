#include <bits/stdc++.h>
using namespace std;

int maxLen(int n, int x, int y, int z, int* dp) {
    // we can reach n from three states, n - x, n - y and n - z, considering that x, y, z are less than n
    // soo we make cuts at these three posns and ask them to get their answers recursively and add 1 to them, and take max

    // base case, n == 0, rod length 0
    if(n == 0) {
      dp[n] = 0;
      return 0;
    }

    // check if state already calculated
    if(dp[n] > -1) {
      return dp[n];
    }

    int len1 = INT_MIN, len2 = INT_MIN, len3 = INT_MIN;
    if(x <= n) {
      len1 = 1 + maxLen(n - x, x, y, z, dp);
    }
    if(y <= n) {
      len2 = 1 + maxLen(n - y, x, y, z, dp);
    }
    if(z <= n) {
      len3 = 1 + maxLen(n - z, x, y, z, dp);
    }
    dp[n] = max(len1, max(len2, len3));
    return dp[n];
}

int maxSegments_iterative(int n, int x, int y, int z) {
  int dp[n + 1];
  dp[0] = 0;
  for(int i = 1; i <= n; i++) {
    int o1 = INT_MIN, o2 = INT_MIN, o3 = INT_MIN;
    if(x <= i) {
      o1 = 1 + dp[i - x];
    }
    if(y <= i) {
      o2 = 1 + dp[i - y];
    }
    if(z <= i) {
      o3 = 1 + dp[i - z];
    }
    dp[i] = max(o1, max(o2, o3));
  }
  //for(int i = 0; i <= n; i++) cout << dp[i] << " ";
  return dp[n];
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    // int dp[n + 1];
    // for(int i = 0; i <= n; i++) {
    //   dp[i] = -1;
    // }
    //cout << maxLen(n, x, y, z, dp) << endl;
    cout << maxSegments_iterative(n, x, y, z) << endl;
  }
}
