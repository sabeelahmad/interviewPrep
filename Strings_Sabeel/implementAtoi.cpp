#include <bits/stdc++.h>
using namespace std;

int _atoi(string s) {
  int len = s.size();
  int number = 0;
  int place = 1;
  int neg = 1;
  if (s[0] == '-') {
    neg = -1;
  }
  reverse(s.begin(), s.end());
  for(int i = 0; i < len; i++) {
    if(s[i] - '0' > 10) {
      return -1;
    }
    if(s[i] - '0' >= 0 && s[i] - '0' <=9) {
      number = number + (place * (s[i] - '0'));
      place = place * 10;
    }
  }
  return neg*number;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    string s;
    cin >> s;
    cout << _atoi(s) << endl;
  }
}
