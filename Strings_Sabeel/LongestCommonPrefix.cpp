#include <bits/stdc++.h>
using namespace std;

void longestCommonPrefix(vector<string> v) {
  if (v.size() == 1) {
    cout << v[0] << endl;
    return;
  }

  string tprefix = "", prefix="";
  for(int i = 0; i < v.size() - 1; i++) {
    string a, b;
    if (i == 0) {
      a = v[i];
      b = v[i + 1];
    } else {
      a = tprefix;
      b = v[i + 1];
    }
    if(i != 0 && tprefix.size() == 0) {
      cout << -1 << endl;
      return;
    }
    int j = 0, k = 0;
    while(a[j] == b[k] && j < a.size() && k < b.size()) {
      prefix += a[j];
      j++;
      k++;
    }
    tprefix = prefix;
    prefix="";
  }
  cout << tprefix << endl;
  return;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<string> v;
    for(int i = 0; i < n; i++) {
      string temp;
      cin >> temp;
      v.push_back(temp);
    }
    longestCommonPrefix(v);
  }
  return 0;
}
