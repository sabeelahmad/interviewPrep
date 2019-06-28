#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007
using namespace std;

ll AP(ll * a, int n) {
    ll f = a[0];
    ll d = a[1] - f;
    for(int i = 2; i < n; i++) {
      if(a[i] == 0) return false;
      if(a[i] - a[i - 1] != d) {
        return false;
      }
    }
    return true;
}

ll GP(ll * a , int n) {
    ll f = a[0];
    ll r = a[1] / f;
    if(a[1]%f != 0) {
      return false;
    }
    //cout << "GP r " << r << endl;
    for(int i = 2; i < n; i++) {
      if(a[i] == 0) return false;
      if(a[i] / a[i - 1] != r || a[i]%a[i-1] != 0) {
        return false;
      }
    }
    return true;
}

ll FIBO(ll * a, int n) {
    ll f = a[0];
    ll f2 = a[1];
    for(int i = 2; i < n; i++) {
      if(a[i] != f + f2) {
        return false;
      }
      f = f2;
      f2 = a[i];
    }
    return true;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }

    // AP check
    if(AP(a, n)) {
      //cout << "AP" << endl;
      ll f = a[0];
      ll d = a[1] - f;
      // n + 1 th term
      ll ans = (f%mod + (n+1-1)*d%mod)%mod;
      cout << ans << endl;
    }
    // GP check
    else if(GP(a, n)) {
      //cout << "GP" << endl;
      ll f = a[0];
      ll r = a[1] / f;
      //cout << r << endl;
      // n + 1 th term
      ll p = pow(r, n);
      ll ans = ((f%mod) * (p%mod))%mod;
      cout << ans << endl;
    }
    // FIBO check
    else if(FIBO(a, n)) {
      //cout << "FIB" << endl;
      // sum of last two terms
      ll ans = (a[n-1]%mod + a[n-2]%mod)% mod;
      cout << ans << endl;
    } else {
      cout << -99999 << endl;
    }
  }
}
