#include<bits/stdc++.h>
using namespace std;

int longestValidParanthesis(string s) {
  int n = s.length();
  stack<int> st; // we will push indices of opening brackets to this
  // when a closing bracket is found, we pop stack whose top is usually an opening bracket , and find length and max accordingly
  st.push(-1); // acts as base for 0
  int mx = INT_MIN;
  for(int i = 0; i < n; i++) {
    if(s[i] == '(') {
      st.push(i);
    }
    else if(s[i] == ')') {
      // pop closing bracket
      st.pop();
      // if not empty
      if(!st.empty()) {
        mx = max(mx, i - st.top());
      }
      // if empty, push i to stack
      else {
        st.push(i); // acts as base for next valid substring
      }
    }
  }
  return mx;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	   string s;
     cin >> s;
     cout << longestValidParanthesis(s) << endl;
	}
	return 0;
}
