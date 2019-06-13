#include<bits/stdc++.h>
using namespace std;

int min_coins(int* deno, int nC, int n) {
  // basic recursive solution
    // if(n == 0) {
    //     return 0;
    // }
    //
    // int a = INT_MAX;
    // for(int i = 0; i < 10; i++) {
    //     if(deno[i] <= n) {
    //        a = 1+min(a, (min_coins(deno, nC, n - deno[i])));
    //     }
    // }
    // return a;

  // using dynamic programming
  int dp[n + 1];
  for(int i = 0; i < n + 1; i++) {
    dp[i] = INT_MAX;
  }
  dp[0] = 0;
  int bt[n + 1];
  bt[0] = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < 10; j++) {
      if(deno[j] <= i) {
        int smallAns = dp[i - deno[j]];
        if(smallAns != INT_MAX && smallAns + 1 < dp[i]) {
          dp[i] = smallAns + 1;
          bt[i] = deno[j];
        }
      }
    }
  }
  // coins that make up the value
  int k = n;
  vector<int> a;
  while(k != 0) {
    a.push_back(bt[k]);
    k = k - bt[k];
  }
  sort(a.begin(), a.end(), greater<int>());
  for(int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << endl;
  // value of min coins needed = return dp[n];
}

int main()
 {
	//code
	int t;
	cin >> t;
	int deno[10] = {1,2,5,10,20,50,100,200,500,2000}; // 10
	while(t--) {
	    int n;
	    cin >> n;
	    min_coins(deno, 10, n);
	}
	return 0;
}
