#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    string s1, s2;
    cin >> s1 >> s2;
    int a[26] = {0};
    int b[26] = {0};
    for(int i = 0; i < s1.length() ; i++) {
      a[s1[i] - 'a']++; // subtracting a to get index value since a - 'a' = 0, b - 'a' = 1 and so on
    }
    for(int i = 0; i < s2.length(); i++) {
      b[s2[i] - 'a']++;
    }
    bool ans = true;
    for(int i = 0; i < 26; i++) {
      if(a[i] != b[i]) {
        ans = false;
        break;
      }
    }
    if(ans) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
