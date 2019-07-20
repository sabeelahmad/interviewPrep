#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

int totalDecodings(string s, int n, int dp[]) {
    // Empty string means one decoding
    if(n == 0) {
        dp[0] = 1;
        return 1;
    }
    if(n < 0) {
        return 0;
    }
    // if state already calculated
    if(dp[n] > -1) {
        return dp[n];
    }
    if(s[0] == '0') {
        return 0;
    }
    int ways1 = 0, ways2 = 0;
    ways1 = totalDecodings(s.substr(1), n - 1, dp);
    // if first two digits less than 26
    int x = stoi(s.substr(0, 2));
    if(x >= 10 && x <= 26) {
        ways2 = totalDecodings(s.substr(2), n - 2, dp);
    }
    dp[n] = ways1 + ways2;
    return dp[n];
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    string s;
	    cin >> s;
	    int dp[n + 1];
	    memset(dp, -1, sizeof(dp));
	    cout << totalDecodings(s, n, dp) << endl;
	}
	return 0;
}
