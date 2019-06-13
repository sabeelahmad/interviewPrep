#include <bits/stdc++.h>
using namespace std;

bool subset_sum(int * arr, int n, int k, int ** dp) {
    if(n == 0) {
      if (k == 0) {
	dp[n][k] = 1;
        return true;
      } else {
	dp[n][k] = 0;
        return false;
      }      
    }
    if(k < 0) {
      return false;
    }
    if(k == 0) {
      dp[n][k] = 1;
      return true;
    }
    if(dp[n][k] > -1) {
     return dp[n][k];
    }
    // include
    bool o1 = subset_sum(arr + 1, n - 1, k - arr[0], dp);
    // exclude
    bool o2 = subset_sum(arr + 1, n - 1, k, dp);
    dp[n][k] = (o1 | o2);
    return dp[n][k];
} 

int main() {
    int n;
    cin >> n;
    int * arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    int ** dp = new int*[n + 1];
    for(int i = 0; i <= n; i++) {
        dp[i] = new int[k + 1];
	for(int j = 0; j <= k; j++) {
	    dp[i][j] = -1;
	}
    }
    if(subset_sum(arr, n, k, dp)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
