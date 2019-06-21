#include<bits/stdc++.h>
using namespace std;

// we can either pick a coin or not
int waysToMakeChange(int* a, int n, int k, int ** dp) {
    // base cases
    if(k == 0) {
        return 1;
    }
    if(k < 0) {
        return 0;
    }
    if(n == 0) {
        return 0;
    }

    // check if this state of n,k already calculated
    if(dp[n][k] > -1) {
        return dp[n][k];
    }

    int option1, option2;
    // pick coin, we can again pick this as well
    option1 = waysToMakeChange(a, n, k - a[0], dp);
    // dont pick coin - we dont consider it ever again
    option2 = waysToMakeChange(a + 1, n - 1, k, dp);
    // total ways is sum of two options
    dp[n][k] = option1 + option2;
    return dp[n][k];
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
	    int k;
	    cin >> k;
	    int ** dp = new int*[n+1];
	    for(int i = 0; i < n + 1; i++) {
	        dp[i] = new int[k + 1];
	        for(int j = 0; j < k + 1; j++) {
	            dp[i][j] = -1;
	        }
	    }
	    cout << waysToMakeChange(a, n, k, dp) << endl;
	}
	return 0;
}
