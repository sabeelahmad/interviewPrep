#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  bool sieve[10001];
  memset(sieve, true, sizeof(sieve));
  // build sieve
  for(int i = 2; i*i <= 10000; i++) {
    if(sieve[i]) {
      // mark multiples starting from i*i false
      for(int j = i*i; j <= 10000; j += i) {
        sieve[j] = false;
      }
    }
  }

  while(t--) {
    int n;
    cin >> n;
    // find first prime less than n, then use two pointer approach to find pair whose sum is n
    int r;
    for(int i = n; i >= 2; i--) {
      if(sieve[i]) {
        r = i;
        break;
      }
    }
    // now use two pointer technique to find pair
    int l = 2;
    while(l < r) {
      if(!sieve[l]) {
        l++;
        continue;
      }
      if(!sieve[r]) {
        r--;
        continue;
      }
      if(l + r == n) {
        cout << l << " " << r << endl;
        break;
      } else if(l + r > n) {
        r--;
      } else if(l + r < n) {
        l++;
      }
    }
  }
}
