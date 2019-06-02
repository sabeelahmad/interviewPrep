#include <bits/stdc++.h>
using namespace std;

// used sliding window

int main() {
  int t;
  cin >> t;
  while(t--) {
    string s;
    cin >> s;
    int arr[256] = {0};
    int size = s.size();
    int maxlen = 1, currlen = 1;
    int start = 0;
    arr[s[0]]++;
    for(int i = 1; i < size;) {
      if (arr[s[i]] == 1) {
        // if seen remove from current substring
        // and consider next substring
        //arr[s[start]]--;
        arr[s[start]]--;
        start++;
        maxlen=max(maxlen, currlen);
        currlen -= 1;
      } else {
        arr[s[i]]++;
        currlen++;
        i++;
      }
    }
    cout << max(maxlen, currlen) << endl;
  }
}
