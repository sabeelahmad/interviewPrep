#include <bits/stdc++.h>
using namespace std;

void reverseWords(string &s) {
  // words separated by dots
  // first reverse whole string
  // then reverse each word
  for(int i = 0, j = s.length() - 1; i < j; i++, j--) {
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }

  for(int i = 0; i < s.length();) {
    int start = i, end = i;
    while(s[i] != '.' && i < s.length()) {
      end = i;
      i++;
    }
    i = end + 1;
    for(int j = start, k = end; j < k; j++, k--) {
      char temp = s[j];
      s[j] = s[k];
      s[k] = temp;
    }
  }
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    string s;
    cin >> s;
    reverseWords(s);
    cout << s << endl;
  }
}
