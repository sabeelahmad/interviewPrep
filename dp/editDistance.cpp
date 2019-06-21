#include<bits/stdc++.h>
using namespace std;

int editDistanceHelper(string s1, string s2, int n1, int n2, int ** dp) {
    // if one of the strings is empty, edit distance is simply remaining
    // length of other string
    if(n1 == 0) {
        return n2;
    }
    if(n2 == 0) {
        return n1;
    }

    if(dp[n1][n2] > -1) {
        return dp[n1][n2];
    }

    if(s1[0] == s2[0]) {
        dp[n1][n2] = editDistanceHelper(s1.substr(1), s2.substr(1), n1 - 1, n2 - 1, dp);
    } else {
        dp[n1][n2] = 1 + min(editDistanceHelper(s1.substr(1), s2.substr(1), n1 - 1, n2 - 1, dp),
        min(editDistanceHelper(s1.substr(1), s2, n1 - 1, n2, dp), editDistanceHelper(s1, s2.substr(1), n1, n2 - 1, dp)));
    }
    return dp[n1][n2];
}

int editDistance(string s1, string s2, int n1, int n2) {
    int ** dp = new int*[n1 + 1];
    for(int i = 0; i < n1 + 1; i++) {
        dp[i] = new int[n2 + 1];
        for(int j = 0; j < n2 + 1; j++) {
            dp[i][j] = -1;
        }
    }
    return editDistanceHelper(s1, s2, n1, n2, dp);
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n1, n2;
	    cin >> n1 >> n2;
	    string s1, s2;
	    cin >> s1 >> s2;
	    cout << editDistance(s1, s2, n1, n2) << endl;
	}
	return 0;
}
