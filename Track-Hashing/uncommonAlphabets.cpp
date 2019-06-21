#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    string s1, s2;
    cin >> s1 >> s2;
    set<char> ans;
    unordered_map<char, int> map_s1;
    unordered_map<char, int> map_s2;

    map_s1.clear();
    map_s2.clear();

    int n1 = s1.length();
    int n2 = s2.length();

    for(int i = 0; i < n1; i++) {
      if(map_s1[s1[i]] == 0) {
        map_s1[s1[i]] = 1;
      } else {
        map_s1[s1[i]] = map_s1[s1[i]] + 1;
      }
    }

    for(int i = 0; i < n2; i++) {
      if(map_s2[s2[i]] == 0) {
        map_s2[s2[i]] = 1;
      } else {
        map_s2[s2[i]] = map_s2[s1[i]] + 1;
      }
    }

    for(int i = 0; i < n1; i++) {
      if(map_s2[s1[i]] == 0) {
        ans.insert(s1[i]);
      }
    }

    for(int i = 0; i < n2; i++) {
      if(map_s1[s2[i]] == 0) {
        ans.insert(s2[i]);
      }
    }

    for(auto itr = ans.begin(); itr != ans.end(); itr++) {
      cout << *itr;
    }
    cout << endl;
  }
}
