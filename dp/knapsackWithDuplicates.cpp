#include<bits/stdc++.h>
using namespace std;

int knpDup(int values[], int weights[], int n, int W, int** dp) {
    if(W == 0) {
        dp[n][W] = 0;
        return 0;
    }
    if(n == 0) {
        dp[n][W] = 0;
        return 0;
    }
    if(dp[n][W] != -1) {
        return dp[n][W];
    }
    // include weight if in bounds
    int x = INT_MIN, y = INT_MIN;
    if(weights[0] <= W) {
        x = knpDup(values, weights, n, W - weights[0], dp) + values[0];
    }
    // exclude weight altogether
    y = knpDup(values + 1, weights + 1, n - 1, W, dp);
    dp[n][W] = max(x, y);
    return dp[n][W];
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n, W;
	    cin >> n >> W;
	    int values[n];
	    int weights[n];
	    for(int i = 0; i < n; i++) {
	        cin >> values[i];
	    }
	    for(int i = 0; i < n; i++) {
	        cin >> weights[i];
	    }
	    int** dp = new int*[n + 1];
	    for(int i = 0; i < n + 1; i++) {
	        dp[i] = new int[W + 1];
	        for(int j = 0; j < W + 1; j++) {
	            dp[i][j] = -1;
	        }
	    }
	    cout << knpDup(values, weights, n, W, dp) << endl;
	}
	return 0;
}
