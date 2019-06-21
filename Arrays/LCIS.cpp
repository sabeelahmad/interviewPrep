#include<bits/stdc++.h>
using namespace std;

int LCIS(int* a, int* b, int n, int m) {
    // we use LCS + LIS here
    // we store a 1D dp table, and for each pair a[i], b[j], we store LCIS in it
    int dp[m] = {0};
    for(int i = 0; i < n; i++) {
        int current = 0;
        for(int j = 0; j < m; j++) {
            // if a[i] and b[j] are same, LCIS gets increased by 1
            // if its greater than LCIS already at dp[j] update it
            if(a[i] == b[j] && current + 1 > dp[j]) {
                dp[j] = current + 1;
            }
            // if a[i] > b[j]
            if(a[i] > b[j] && dp[j] > current) {
                current = dp[j];
            }
        }
        for(int p = 0; p < m; p++) {
          cout << dp[p] << " ";
        }
        cout << endl;
    }
    int ans = 0;
    for(int i = 0; i < m; i++) {
        ans = max(ans, dp[i]);
    }
    return ans;
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
	    int m;
	    cin >> m;
	    int b[m];
	    for(int i = 0; i < m; i++) {
	        cin >> b[i];
	    }
	    cout << LCIS(a, b, n, m) << endl;
	}
	return 0;
}
