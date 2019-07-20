#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

int minCoins(int coins[], int n, int val, int dp[]) {
    if(val == 0) {
        dp[val] = 0;
        return 0;
    }
    // try each coin
    if(dp[val] != -1) {
        return dp[val];
    }
    int ways = INT_MAX;
    for(int i = 0; i < n; i++) {
        if(coins[i] <= val) {
            ways = min(ways, minCoins(coins, n, val - coins[i], dp));
        }
    }

    if(ways != INT_MAX) {
        dp[val] = ways + 1;
    }
    else {
        dp[val] = ways;
    }
    return dp[val];
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n, val;
	    cin >> n >> val;
	    int coins[n];
	    for(int i = 0; i < n; i++) {
	        cin >> coins[i];
	    }
	    int dp[val + 1];
	    memset(dp, -1, sizeof(dp));
	    int p = minCoins(coins, n, val, dp);
	    if(p == INT_MAX) {
	        cout << -1 << endl;
	    } else {
	        cout << p << endl;
	    }

	}
	return 0;
}
