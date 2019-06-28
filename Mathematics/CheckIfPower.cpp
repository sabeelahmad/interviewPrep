#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

bool isPower(ll x, ll y) {
  // if log y to base x is whole no then it is power else not
  ld log_y_x = log(y)/log(x);
  // if log_y_x is whole no and then ans is true
  if(int(log_y_x)-log_y_x == 0) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    ll x, y;
    cin >> x >> y;
    cout << isPower(x, y) << endl;
  }
}
