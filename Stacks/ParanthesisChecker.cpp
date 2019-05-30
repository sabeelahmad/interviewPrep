#include <bits/stdc++.h>
using namespace std;

void checkBalancedParanthesis(string s) {
  stack <char> st;
  //bool flag = false;
  for(int i = 0; i < s.length(); i++) {
    if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
      st.push(s[i]);
    } else if (st.empty()) {
      // If not opening bracket and stack is empty
      // means closing bracket but no corresponding opening bracket
      // hence unbalanced
      cout << "not balanced";
      return;
    } else {
      // 3 cases
      // )
      if(s[i] == ')') {
        if(st.top() == '(') {
          st.pop();
        } else {
          cout << "not balanced";
          return;
        }
      }
      // ]
      else if(s[i] == ']') {
        if(st.top() == '[') {
          st.pop();
        } else {
          cout << "not balanced";
          return;
        }
      }
      // }
      else if(s[i] == '}') {
        if(st.top() == '{') {
          st.pop();
        } else {
          cout << "not balanced";
          return;
        }
      }
    }
  }
  if(st.empty()) {
    cout << "balanced";
  } else {
    cout << "not balanced";
  }
}


int main() {
  int t;
  cin >> t;
  while(t--) {
    string s;
    cin >> s;
    checkBalancedParanthesis(s);
    cout << endl;
  }
}
