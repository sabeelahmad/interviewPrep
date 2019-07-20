#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define MAX 101

ll countPaths(int x, int y, int m, int n, int dp[MAX][MAX]) {
    // if out of bounds no way
    if(x < 0 || y < 0 || x >= m || y >= n) {
        return 0;
    }
    // if final destination reached, 1 path is found
    if(x == m - 1 && y == n - 1) {
        return 1;
    }
    // if state already calculated
    if(dp[x][y] != -1) {
        return dp[x][y];
    }

    ll way1 = countPaths(x + 1, y, m , n, dp) % mod;
    ll way2 = countPaths(x, y + 1, m , n, dp) % mod;
    dp[x][y] = (way1 + way2);
    dp[x][y] = dp[x][y] % mod;
    return dp[x][y];
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int m, n;
	    cin >> m >> n;
	    int dp[MAX][MAX];
	    memset(dp, -1, sizeof(dp));
	    cout << countPaths(0, 0, m, n, dp) << endl;
	}
	return 0;
}
