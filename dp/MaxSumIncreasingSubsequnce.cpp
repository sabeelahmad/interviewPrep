#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// simply variation of lis, here rather than calculating length of lis in dp table , we maintain sum of lis

ll msis(int* a, int n, ll* dp) {
  dp[0] = a[0];
  for(int i = 1; i < n; i++) {
    dp[i] = a[i];
    for(int j = i - 1; j >= 0; j--) {
      if(a[j] < a[i] && dp[j] + a[i] > dp[i]) {
        dp[i] = dp[j] + a[i];
      }
    }
  }
  ll maxsum = 0;
  for(int i = 0; i < n; i++) {
    maxsum = max(maxsum, dp[i]);
  }
  return maxsum;
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
    ll dp[n];
    memset(dp, 0, sizeof(dp));
    cout << msis(a, n, dp) << endl;
  }
}
