#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    string s;
    cin >> s;
    int n = s.size();
    // using dp table of n*n to consider all possible substrings
    bool dp[n][n];
    int start, maxLength = 1; // 1 because single character strings are palindromes
    memset(dp, false, sizeof(dp));
    // fill table for case of 1 length substrings
    for(int i = 0; i < n; i++) {
      dp[i][i] = true;
    }

    // fill table for case of 2 length substrings
    // consider consectuive substrings
    start = 0;
    for(int i = 0; i < n - 1; i++) {
      if(s[i] == s[i + 1]) {
        dp[i][i + 1] = true;
        maxLength = 2;
        start = i;
      }
    }

    // consider substrings of length 3 and greater now
    for(int k = 3; k <= n; k++) {
      // start substrings from index 0
      for(int i = 0; i < n - k + 1; i++) {
        // calculate j, susbtring should be from i to j of length k
        int j = i + k - 1;
        // check if s[i+1...j-1] is palindrome & s[i] == s[j] then this substring is a palindrome
        if(dp[i+1][j-1] && s[i] == s[j]) {
          dp[i][j] = true;
          // update maxlen if better
          if(k > maxLength) {
            maxLength = k;
            start = i;
          }
        }
      }
    }

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        cout << dp[i][j] << " ";
      }
      cout << endl;
    }

    cout << s.substr(start, maxLength) << endl;
  }
}
