#include<bits/stdc++.h>
using namespace std;

void printBracketNumber(string s) {
  int n = s.length();
  stack< pair<char, int> > st;
  int bracketNum = 1;
  for(int i = 0; i < n; i++) {
    // if a new opening bracket, push to stack and assign it number
    if(s[i] == '(') {
      cout << bracketNum << " ";
      st.push(make_pair(s[i], bracketNum));
      bracketNum++;
    }
    // if closing bracket, pop topmost, and output its bracketnum
    if(s[i] == ')') {
      cout << st.top().second << " ";
      st.pop();
    }
  }
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	   string s;
     cin >> s;
     printBracketNumber(s);
     cout << endl;
	}
	return 0;
}
