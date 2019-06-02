#include <bits/stdc++.h>
using namespace std;

int romanNumeralMapper(char c) {
  if (c == 'I') {
    return 1;
  }
  if (c == 'V') {
    return 5;
  }
  if (c == 'X') {
    return 10;
  }
  if (c == 'L') {
    return 50;
  }
  if (c == 'C') {
    return 100;
  }
  if (c == 'D') {
    return 500;
  }
  if (c == 'M') {
    return 1000;
  }
}

int romanToInt(string s) {
  int ans = 0;
  int size = s.size();
  if (s.size() == 1) {
    return romanNumeralMapper(s[0]);
  }
  for(int i = 0; i < size - 1;) {
    if(romanNumeralMapper(s[i]) >= romanNumeralMapper(s[i+1])) {
      ans += romanNumeralMapper(s[i]);
      i++;
    } else {
      ans += (romanNumeralMapper(s[i + 1]) - romanNumeralMapper(s[i]));
      i+=2;
    }
  }
  if(romanNumeralMapper(s[size - 2]) >= romanNumeralMapper(s[size -1])) {
    ans += romanNumeralMapper(s[size - 1]);
  }
  return ans;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    string s;
    cin >> s;
    cout << romanToInt(s) << endl;
  }
}
