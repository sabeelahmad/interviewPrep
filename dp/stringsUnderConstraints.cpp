#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define MAX 1001

int possibleStrings(int n, int bCount, int cCount, int dp[MAX][2][3]) {
    // if allowed b's or c's less than 0, string formation not possible
    if(bCount < 0 || cCount < 0) {
        return 0;
    }
    // if length achieved
    if(n == 0) {
        return 1;
    }
    // if 1 b and 2 c's used, rest can be all a's so 1 more string formed
    if(bCount == 0 && cCount == 0) {
        return 1;
    }

    if(dp[n][bCount][cCount] != -1) {
        return dp[n][bCount][cCount];
    }

    int res = possibleStrings(n - 1, bCount, cCount, dp);
    res += possibleStrings(n - 1, bCount - 1, cCount, dp);
    res += possibleStrings(n - 1, bCount, cCount - 1, dp);
    dp[n][bCount][cCount] = res%mod;
    return dp[n][bCount][cCount];
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    int dp[MAX][2][3];
	    memset(dp, -1, sizeof(dp));
	    cout << possibleStrings(n, 1, 2, dp) << endl;
	}
	return 0;
}
