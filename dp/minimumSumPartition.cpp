#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }

    // this problem is a variation of subset sum problem
    // we make a dp table and generate all possible sums using subset sum concept
    // then we get minimum difference of two partitions using the dp table

    int ** dp = new int*[n + 1];
    for(int i = 0; i <= n; i++) {
      dp[i] = new int[sum + 1];
      for(int j = 0; j <= sum; j++) {
        dp[i][j] = -1;
      }
    }

    // fill base cases
    for(int i = 0; i <= n; i++) {
      dp[i][0] = 1;
    }

    for(int i = 1; i <= sum; i++) {
      dp[0][i] = 0;
    }

    // fill dp table
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= sum; j++) {
        // exculde ith element
        dp[i][j] = dp[i - 1][j];
        // include ith if value less than j
        if(a[i - 1] <= j) {
          dp[i][j] |= dp[i - 1][j - a[i - 1]];
        }
      }
    }
    
    // now we loop from sum/2 to 0, we find the largest j that is closest to sum/2,means j 2*j is closest to sum
    // this will give the min difference, as the two partitions will be as close to a perfect split of sums

    for(int j = sum/2; j >= 0; j--) {
      if(dp[n][j]) {
        cout << sum - (2*j) << endl;
        break;
      }
    }
  }
}
