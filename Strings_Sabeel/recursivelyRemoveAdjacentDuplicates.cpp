#include <bits/stdc++.h>
using namespace std;

// we make it bool for cases like mississipie in which second iteration over string might be required
bool removeDups(char *s) {
  if(s[0] == '\0') {
    return false;
  }

  int size = 0;
  while(s[size] != '\0') {
    size++;
  }

  int i = 1;
  while(s[0] == s[i] && i < size) {
    i++;
  }

  if(i == 1) {
    return removeDups(s + 1) | false;
  } else {
    int j;
    for(j = 0; s[i] != '\0'; j++){
      s[j] = s[i];
      i++;
    }
    s[j] = '\0';
    return removeDups(s) | true;
  }

}

int main() {
  int t;
  cin >> t;
  while(t--) {
    char s[100];
    cin >> s;
    while (removeDups(s));
    cout << s << endl;
  }
}
