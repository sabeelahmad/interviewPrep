#include <bits/stdc++.h>
using namespace std;

void removeDuplicates(string str) {
  // using bit magic
  // we use a 32 bit integer and mark its bits to check if character already seen or not
  // a will be bit 0, therefore to get bit we do s[i] - 97 or s[i] - 'a'
  int counter = 0;
  // keeps track of visited characters
  int i = 0;
  int size = str.size();
  // gets character value
  int x;
  // keeps track of length of resultant string
  int length = 0;
  while (i < size) {
      x = str[i] - 97;
      // check if Xth bit of counter is unset
      if ((counter & (1 << x)) == 0) {
          str[length] = str[i];
          // mark current character as visited
          counter = counter | (1 << x);
          length++;
      }
      i++;
  }
  cout << str.substr(0, length) << endl;
}

int main() {
  int t;
  cin >> t;
  cin.ignore();
  while(t--) {
    string s;
    getline(cin, s);
    removeDuplicates(s);
  }
}
