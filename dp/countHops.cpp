// A frog jumps either 1, 2 or 3 steps to go to top. In how many ways can it reach the top
// This is a variation of stair case problem
// we will use iterative approach

#include <bits/stdc++.h>
using namespace std;

int getTotalWaysTillTop(int n) {
  // make dp array, dp[i] will store ways to get till i
  int dp[n + 1];
  // base cases
  dp[0] = 0; // no way to go till 0
  dp[1] = 1; // one way to go till 1, take step =1
  dp[2] = 2; // 1,1 and 2
  dp[3] = 4; // 1,1,1 + 1,2 + 2,1 + 3
  dp[4] = 7;   // 1,1,1,1 + 1,1,2 + 1,3 + 1,2,1 + 2,2, + 3,1 + 2,1,1
  // for each dp[i], we can get to dp[i] from three state dp[i - 1] - 1 step, dp[i - 2] - 2 steps, dp[i - 3] - 3 steps
  // total ways will be sum of these 3 previous states
  for(int i = 5; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
  }
  return dp[n];
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    cout << getTotalWaysTillTop(n) << endl;
  }
}
