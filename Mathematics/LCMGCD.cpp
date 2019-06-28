#include <bits/stdc++.h>
using namespace std;

// euclidean hcf method
int getGCD(int a, int b) {
  if(b == 0) {
    return a;
  }
  return getGCD(b, a % b);
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int a, b;
    cin >> a >> b;
    int gcd = getGCD(a, b);
    int lcm = (a*b)/gcd;
    cout << lcm << " " << gcd << endl;
  }
}
