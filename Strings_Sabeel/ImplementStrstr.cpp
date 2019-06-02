#include <bits/stdc++.h>
using namespace std;

int _strstr(string s, string x) {
  int j = 0;
  int s_len = s.size(), x_len = x.size();
  for(int i = 0; i < s_len; i++) {
    if(s.substr(i, x_len) == x) {
      return i;
    }
  }
  return -1;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    string s, x;
    cin >> s >> x;
    cout << _strstr(s, x) << endl;
  }
}
