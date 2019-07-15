#include<bits/stdc++.h>
using namespace std;

int evaluate(string s) {
  int n = s.length();
  stack<int> st;
  for(int i = 0; i < n; i++) {
    // if not operator push to stack
    if(isdigit(s[i])) {
      st.push(s[i] - '0');
    } else {
      // if operator perform operation
      int a = st.top();
      st.pop();
      int b = st.top();
      st.pop();
      // check what op
      if(s[i] == '*') st.push(b*a);
      if(s[i] == '+') st.push(b+a);
      if(s[i] == '-') st.push(b-a);
      if(s[i] == '/') st.push(b/a);
    }
  }
  return st.top(); 
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	   string s;
     cin >> s;
     cout << evaluate(s) << endl;
	}
	return 0;
}
