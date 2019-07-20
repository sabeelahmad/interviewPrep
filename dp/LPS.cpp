#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define MAX 1001

int lps(string s, int i, int j, int dp[MAX][MAX]) {
    // If only one character
    if(i == j) {
        return 1;
    }
    // If two characters and they are same
    if(s[i] == s[j] && i + 1 == j) {
        return 2;
    }
    // if state calculated
    if(dp[i][j] > -1) {
        return dp[i][j];
    }
    // If first and last characters match
    if(s[i] == s[j]) {
        dp[i][j] = lps(s, i + 1, j - 1, dp) + 2;
    } else {
        // get max of, move ahead from front by 1 or move from back by 1
        dp[i][j] = max(lps(s, i, j - 1, dp), lps(s, i + 1, j, dp));
    }
    return dp[i][j];
}

int lps2(string s) {
    int n = s.length();
    int dp[n][n];
    for(int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    // for 2 length to n
    for(int k = 2; k <= n; k++) {
        for(int i = 0; i + k - 1 < n; i++) {
            int j = i + k - 1;
            if(s[i] == s[j] && k == 2) {
                dp[i][j] = 2;
            }
            else if(s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else {
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    string s;
	    cin >> s;
	    int n = s.size();
	    //int dp[MAX][MAX];
	    //memset(dp, -1, sizeof(dp));
	    cout << lps2(s) << endl;
	}
	return 0;
}
