#include <bits/stdc++.h>
using namespace std;

string decode(string s) {
  int n = s.length();
  // we will use two stacks one for integer and other for chars
  stack<int> intStack;
  stack<char> charStack;
  string temp = "", result = "";
  for(int i = 0; i < n; i++) {
    // if digit, see what number is formed can be more than one digit and add it to integer stack
    int num = 0;
    if(s[i] >= '0' && s[i] <= '9') {
      while(s[i] >= '0' && s[i] <= '9') {
        num = (num * 10) + (s[i] - '0');
        i++;
      }
      i--;
      intStack.push(num);
    }
    // if closing bracket, form string by popping chars till opening bracket found, then repeat it top of intstack tiems
    // then push thsese chars back to stack
    else if(s[i] == ']') {
      temp = "";
      num = 0;
      // get count
      if(!intStack.empty()) {
        num = intStack.top();
        intStack.pop();
      }
      // get chars
      while(!charStack.empty() && charStack.top() != '[') {
        temp = charStack.top() + temp;
        charStack.pop();
      }
      // pop the opening bracket as well
      if(!charStack.empty() && charStack.top() == '[') {
        charStack.pop();
      }
      // repeat string num times
      for(int j = 1; j <= num; j++) {
        result += temp;
      }
      // put the expanded part of string chars back to stack
      for(int j = 0; j < result.length(); j++) {
        charStack.push(result[j]);
      }
      result = "";
    }
    // if opening bracket push to stack
    else if(s[i] == '[') {
      charStack.push('[');
    } else {
      // if a - z push
      charStack.push(s[i]);
    }
  }

  // form final string from stack characters
  while(!charStack.empty()) {
    result = charStack.top() + result;
    charStack.pop();
  }
  return result;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    string s;
    cin >> s;
    cout << decode(s) << endl;
  }
}
