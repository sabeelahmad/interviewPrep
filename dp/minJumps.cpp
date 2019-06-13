#include<bits/stdc++.h>
using namespace std;

// int minJumpsUtil(int * a, int s, int n) {
//     if(s >= n - 1) {
//         // reached end
//         return 0;
//     }
//
//     // for each number in range of number of jumps at a[i]
//     // get min jumps from them , and take min of those
//     int k = a[s];
//     int ans = INT_MAX;
//     for(int i = s + 1; i < s + k + 1 && i < n; i++) {
//         ans = 1 + min(ans, minJumpsUtil(a, i, n));
//     }
//     return ans;
// }

int minJumps(int * a, int n) {
    //return minJumpsUtil(a, 0, n);
    if(a[0] == 0) {
      return -1;
    }

    int dp[n];
    for(int i = 0; i < n; i++) {
      dp[i] = INT_MAX;
    }
    //cout << endl;
    dp[n - 1] = 0;
    //dp[n - 1] = 1;

    for(int i = n - 2; i >= 0; i--) {
      int k = a[i];
      if(k == 0) {
        dp[i] = INT_MAX;
        continue;
      }
      for(int j = i + 1; j <= i + k && j < n; j++) {
        if(dp[j] != INT_MAX && dp[i] > dp[j] + 1) {
          dp[i] = dp[j] + 1;
        }
      }
    }


    // for(int i = 0; i < n; i++) {
    //   cout << dp[i] << " ";
    // }
    // cout << endl;

    // for(int i = 1; i <= k; i++) {
    //  int sAns = minJumps(a+i, n-i);
    //  if(sAns != INT_MAX && 1 + sAns < ans) {
    //    ans = 1 + sAns;
    //  }
    // }
    if(dp[0] == INT_MAX) {
      return -1;
    } else {
      return dp[0];
    };
}

int main()
 {
	//code
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    int * a = new int[n];
	    for(int i = 0; i < n; i++) {
	        cin >> a[i];
	    }
	    cout << minJumps(a, n) << endl;
	    delete [] a;
	}
	return 0;
}
