#include<bits/stdc++.h>
using namespace std;

int rodcutting(int prices[], int n, int dp[]) {
    // base case length of rod is 0, we can make any profit
    if(n <= 0) {
        return 0;
    }
    if(dp[n] > -1) {
        return dp[n];
    }
    // for n we can place a cut at n - 1 to 1
    int maxVal = INT_MIN;
    for(int i = 0; i < n; i++) {
        // we make a cut, so we recur on remaining length
        maxVal = max(maxVal, prices[i] + rodcutting(prices, n - i - 1, dp));
    }
    dp[n] = maxVal;
    return dp[n];
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    int prices[n];
	    for(int i = 0; i < n; i++) {
	        cin >> prices[i];
	    }
	    int dp[n + 1];
	    memset(dp, -1, sizeof(dp));
	    cout << rodcutting(prices, n, dp) << endl;
	}
	return 0;
}
