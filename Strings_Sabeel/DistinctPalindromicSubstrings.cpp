#include <bits/stdc++.h>
using namespace std;

// we will use same concept of longest palindromic substrings
// dp table will have true for all palindromic substrings, but since we want distinct, we will insert them in set

int main() {
  int t;
  cin >> t;
  while(t--) {
    string s;
    cin >> s;
    int n = s.size();
    bool dp[n][n];
    memset(dp, false, sizeof(dp));
    set<string> sx;
    // one length strings
    for(int i = 0; i < n; i++) {
      dp[i][i] = true;
      sx.insert(s.substr(i, 1));
    }

    // two length
    for(int i = 0; i < n - 1; i++) {
      if(s[i] == s[i + 1]) {
        dp[i][i + 1] = true;
        sx.insert(s.substr(i, 2));
      }
    }

    // length 3 and onwards
    for(int k = 3; k <= n; k++) {
      for(int i = 0; i < n - k + 1; i++) {
        int j = i + k - 1;
        if(dp[i+1][j-1] && s[i] == s[j]) {
          dp[i][j] = true;
          sx.insert(s.substr(i, k));
        }
      }
    }

    // set<string>::iterator it;
    // for(it = sx.begin(); it != sx.end(); it++) {
    //   cout << *it << endl;
    // }
    cout << sx.size() << endl;
    }
}
