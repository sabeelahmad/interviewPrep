// Given a set of numbers, check whether it can be partitioned into two subsets such that the sum of elements in both subsets is same or not.
#include <bits/stdc++.h>
using namespace std;

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
    int sum = 0;
    for(int i = 0; i < n; i++) {
      sum += a[i];
    }
    if(sum%2 != 0) {
        cout << "NO" << endl;
        continue;
    }
    int k = sum/2;

    bool ** dp = new bool*[n + 1];
    for(int i = 0; i < n + 1; i++) {
      dp[i] = new bool[k + 1];
    }

    // filling base cases in dp table
    // if k == 0
    for(int i = 0; i <= n; i++) {
      dp[i][0] = true;
    }
    // if n == 0 && k != 0
    for(int i = 1; i <= k; i++) {
      dp[0][i] = false;
    }

    // now fill dp table iteratively
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= k; j++) {
        dp[i][j] = dp[i - 1][j]; // not include
        // if by incldue sum doesnt become < 0
        if(j >= a[i - 1]) {
          dp[i][j] = dp[i][j] || dp[i - 1][j - a[i - 1]];
        }
      }
    }

    if(dp[n][k]) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
