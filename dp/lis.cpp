#include <bits/stdc++.h>
using namespace std;

int lis(int * a, int n) {
  // use simple dp, build array from left to right, for each number check numbers before it if smaller add 1 and pick min of all possible
  int dp[n];
  dp[0] = 1;
  for(int i = 1; i < n; i++) {
    dp[i] = 1;
    for(int j = i - 1; j >= 0; j--) {
      if(a[i] > a[j]) {
        if(dp[j] + 1 > dp[i]) {
          dp[i] = dp[j] + 1;
        }
      }
    }
  }
  int best = -1;
  for(int i = 0; i < n; i++) {
    if(dp[i] > best) {
      best = dp[i];
    }
  }
  return best;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    int * a = new int[n];
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    cout << lis(a, n) << endl;
    delete [] a;
  }
}
