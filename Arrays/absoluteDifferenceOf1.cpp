#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool differenceConditionSatisfied(int x) {
  int prevDigit, currDigit, i = 0;
  while(x > 0) {
    currDigit = x % 10;
    x = x / 10;
    if(i == 0) {
      prevDigit = currDigit;
    } else {
      if(abs(currDigit - prevDigit) != 1) {
        return false;
      } else {
        prevDigit = currDigit;
      }
      i++;
    }
    i++;
  }
  return true;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    ll k;
    cin >> k;
    ll a[n];
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    // we search for array and put all no's that are less than it and have absolute diff of 1 between adjacent digits in a vector
    vector<ll> op;
    for(int i = 0; i < n; i++) {
      if(a[i] < k && a[i] > 9 && differenceConditionSatisfied(a[i])) {
        op.push_back(a[i]);
      }
    }
    if(op.size() == 0) {
      cout << -1 << endl;
    } else {
      for(int i = 0; i < op.size(); i++) {
        cout << op[i] << " ";
      }
      cout << endl;
    }
  }
}
