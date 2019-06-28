#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  bool sieve[10001];
  memset(sieve, true, sizeof(sieve));

  for(int i = 2; i*i <= 10000; i++) {
    if(sieve[i]) {
      for(int j = i*i; j <= 10000; j += i) {
        sieve[j] = false;
      }
    }
  }

  while(t--) {
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++) {
      if(sieve[i]) cout << i << " ";
    }
    cout << endl;
  }
}
