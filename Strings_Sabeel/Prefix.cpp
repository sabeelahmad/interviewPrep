#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
    string s1, s2;
    cin >> s1 >> s2;
    int prefix_start = -1;
    int index = 0;
    int n = s2.size();
    string cprefix = "", fprefix = "";
    int ansIdx;
    for(int i = 0; i < n; i++) {
      if(s2[i] == s1[index]) {
        cprefix += s1[index];
        index++;
        if(prefix_start == -1) {
          prefix_start = i;
        }
      }
      else if(s2[i] != s1[index]) {
        index = 0;
        if(prefix_start != -1 && cprefix.length() > fprefix.length()) {
          ansIdx = prefix_start;
          prefix_start = -1;
          fprefix = cprefix;
          cprefix = "";
        }
      }
    }
    // check after coming out as well
    if(prefix_start != -1 && cprefix.length() > fprefix.length()) {
      ansIdx = prefix_start;
      prefix_start = -1;
      fprefix = cprefix;
      cprefix = "";
    }
    cout << ansIdx << " " << fprefix <<endl;
	}
	return 0;
}
