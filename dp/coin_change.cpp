#include <bits/stdc++.h>
using namespace std;

int coin_change(int n, int * d, int numD, int ** dp) {
 // Base cases
 // 1 - n is 0, can be made in one way
 for(int i = 0; i < numD +  1; i++) {
   dp[0][i] = 1;
 }
 // 2 - no denomination left to consider, no way
 for(int j = 1; j < n + 1; j++) {
   dp[j][0] = 0;
 }
 // 2 choices, either consider coin or not
 // Therefore two calls (n - denomination, numD) and (n, numD + 1)
 for(int i = 1; i < n + 1; i++) {
   for(int j = 1; j < numD + 1; j++) {
     int first = dp[i][j - 1];
     int second;
     if(i - d[j - 1] < 0) {
     	second = 0;
     } else {
        second = dp[i - d[j - 1]][j];
     }
     dp[i][j] = first + second;
   }
 }
 return dp[n][numD];
}


int main(){
   int t;
   cin >> t;
   while(t--) {
      int n;
      cin >> n;
      int numD;
      cin >> numD;
      int * d = new int[numD];
      for(int i = 0; i < numD; i++) {
      	cin >> d[i];
      }
      // allocate 2D table initialized with -1
      int ** dp = new int * [n + 1];
      for(int i = 0; i < n + 1; i++) {
      	dp[i] = new int[numD + 1];
	for(int j = 0; j < numD + 1; j++) {
	   dp[i][j] = -1;
	}
      }
      cout << coin_change(n, d, numD, dp) << endl;
   }
}
