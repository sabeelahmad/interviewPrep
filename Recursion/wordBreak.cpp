#include <bits/stdc++.h>
using namespace std;

// to check if a word in consideration is in dictionary
bool isInDictionary(string &word, vector<string> &dictionary) {
  for(int i = 0; i < dictionary.size(); i++) {
    if(dictionary[i] == word) {
      return true;
    }
  }
  return false;
}

void wordBreakUtil(string s, vector<string> &dictionary, string result, int n) {
    // consider each substring by scanning left to right
    // if a substring found in dict, recur on right part of left part of s
    // if we get a word from there as well we print
    // else we consider other substrings
    for(int i = 1; i <= n; i++) {
      string currPrefix = s.substr(0, i);

      // check if this word is in dictionary
      if(isInDictionary(currPrefix, dictionary)) {
        // if no element left, means we have a possible answer
        if(i == n) {
          result += currPrefix;
          cout << "(" << result << ")";
          return;
        }
        // if not last element, ask for rest of string to see possible word breaks
        wordBreakUtil(s.substr(i, n - i), dictionary, result + currPrefix + " ", n - i);
      }
    }
}

void wordBreak(string s, vector<string> &dictionary) {
  // empty string is passed to keep current sentence for each possible answer while backtracking
  wordBreakUtil(s, dictionary, "", s.length());
  cout << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
      int n;
      cin >> n;
      vector<string> dictionary;
      for(int i = 0; i < n; i++) {
        string d;
        cin >> d;
        dictionary.push_back(d);
      }
      string s;
      cin >> s;
      wordBreak(s, dictionary);
    }
}
