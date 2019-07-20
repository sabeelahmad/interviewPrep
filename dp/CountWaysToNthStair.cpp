#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

int main() {
	int t;
	cin >> t;
	int dp[100001];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= 100000; i++) {
        dp[i] = (dp[i - 1]%mod) + (dp[i - 2]%mod);
        dp[i] = dp[i]%mod;
    }
	while(t--) {
	    int n;
	    cin >> n;
	    cout << dp[n] << endl;
	}
	return 0;
}
