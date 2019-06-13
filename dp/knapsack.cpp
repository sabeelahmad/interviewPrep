#include<bits/stdc++.h>
using namespace std;

// 2 options either pick or not pick, pick if wt less than remaining cap
int knp_memo(int * wt, int * val, int n, int W, int dp[][1010]) {
    if(n == 0) {
        dp[n][W] = 0;
        return 0;
    }
    if(W == 0) {
        dp[n][W] = 0;
        return 0;
    }
    if(dp[n][W] > -1) {
        return dp[n][W];
    }

    int o1 = INT_MIN, o2 = INT_MIN;
    if(wt[0] <= W) {
        o1 = knp_memo(wt + 1, val + 1, n - 1, W-wt[0], dp) + val[0];
        o2 = knp_memo(wt + 1, val + 1, n - 1, W, dp);
    } else {
        o2 = knp_memo(wt + 1, val + 1, n - 1, W, dp);
    }
    dp[n][W] = max(o1, o2);
    return dp[n][W];
}

int knp_it(int *wt, int *val, int n, int W) {
    int dp[n+1][W+1];
    // base cases , n == 0 || W == 0
    for(int i = 0; i <= W; i++) {
        dp[0][i] = 0;
    }
    for(int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    // build dp table bottom up
    for(int i = 1; i <= n; i++) {
        for(int w = 1; w <= W; w++) {
            dp[i][w] = dp[i - 1][w];
            if(wt[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i-1][w-wt[i-1]]);
            }
        }
    }
    return dp[n][W];
}

int main()
 {
	//code
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    int W;
	    cin >> W;
	    int * wt = new int[n];
	    int * val = new int[n];
	    for(int i = 0; i < n; i++) {
	        cin >> val[i];
	    }
	    for(int i = 0; i < n; i++) {
	        cin >> wt[i];
	    }
	    // dp table
	   // int dp[1010][1010];
	   // //memset(dp, -1, sizeof(dp));
	   // for(int i = 0; i <= n; i++) {
	   //     for(int j = 0; j <= W; j++) {
	   //         dp[i][j] = -1;
	   //     }
	   // }
	    //cout << knp_memo(wt, val, n, W, dp) << endl;
	    cout << knp_it(wt, val, n, W) << endl;
	}
	return 0;
}
