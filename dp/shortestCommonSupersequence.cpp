#include <bits/stdc++.h>
using namespace std;

// Shortest common supersequence lenght = (str1.len + str2.len) - LCS.len

int LCSUtil(char* s1, char* s2, int n1, int n2, int** dp) {
  // if one of the strings have been exhausted
  if(n1 == 0 || n2 == 0) {
    //dp[n1][n2] = 0;
    return 0;
  }
  // check if LCS(n1, n2) already solved
  if(dp[n1][n2] > -1) {
    return dp[n1][n2];
  }
  // if first characters of both strings are same, we have 1 character of lcs and move ahead in both strings
  if(s1[0] == s2[0]) {
    dp[n1][n2] =  1 + LCSUtil(s1 + 1, s2 + 1, n1 - 1, n2 - 1, dp);
  } else {
    dp[n1][n2] = max(LCSUtil(s1 + 1, s2, n1 - 1, n2, dp), LCSUtil(s1, s2 + 1, n1, n2 - 1, dp));
  }
  return dp[n1][n2];
}

int LCS(char* s1, char* s2, int n1, int n2) {
  int ** dp = new int*[n1 + 1];
  for(int i = 0; i < n1 + 1; i++) {
    dp[i] = new int[n2 + 1];
    for(int j = 0; j < n2 + 1; j++) {
      dp[i][j] = -1;
    }
  }
  return LCSUtil(s1, s2, n1, n2, dp);
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    char s1[101], s2[101];
    cin >> s1 >> s2;
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    //cout << n1 << " " << n2 << endl;
    int lcsLen = LCS(s1, s2, n1, n2);
    //cout << lcsLen << endl;
    cout << (n1 + n2) - lcsLen << endl;
  }
}
