#include<bits/stdc++.h>
using namespace std;

int solve(int a[], int i, int n, int dp[]) {
    if(i >= n) {
        return 0;
    }
    if(dp[i] > -1) {
        return dp[i];
    }
    dp[i] = max(solve(a, i + 1, n, dp), a[i] + solve(a, i + 2, n, dp));
    return dp[i];
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
	    int dp[n];
	    memset(dp, -1, sizeof(dp));
	    cout << solve(a, 0, n, dp) << endl;
	}
	return 0;
}
