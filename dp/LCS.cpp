#include <bits/stdc++.h>
using namespace std;

int LCSUtil(char* s1, char* s2, int n, int m) {
  if(n == 0 || m == 0) {
    return 0;
  }

  if(dp[n][m] > -1) {
    return dp[n][m];
  }

  // if first chars equal
  if(s1[0] == s2[0]) {
    dp[n][m] = 1 + LCSUtil(s1 + 1, s2 + 1, n - 1, m - 1);
  } else {
    dp[n][m] = max(LCSUtil(s1 + 1, s2 , n - 1, m), LCSUtil(s1, s2 + 1, n, m - 1));
  }
  return dp[n][m];
}

int LCS(char* s1, char* s2) {
  int n = strlen(s1);
  int m = strlen(s2);
  int** dp = new int*[n + 1];
  for(int i = 0; i <= n; i++) {
    dp[i] = new int[m + 1];
    for(int j = 0; j <= m; j++) {
      dp[i][j] = -1;
    }
  }
  return LCSUtil(s1, s2, n, m, dp) << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    char s1[101], s2[101];
    cin >> s1 >> s2;
    cout << LCS(s1, s2) << endl;
  }
}
