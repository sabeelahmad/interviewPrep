#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    string clockwise, anticlockwise;
    // for clockwise move 1st - n-2 and 2nd to n-1
    char clock_n_2 = s1[0];
    char clock_n_1 = s1[1];
    // for anticlockwise move n - 1 to 1st index and n - 2 to 0th
    char anti_1 = s1[n - 1];
    char anti_2 = s1[n - 2];

    int i;
    for(i = 2; i < s1.size(); i++) {
      clockwise += s1[i];
    }
    clockwise += clock_n_2;
    clockwise += clock_n_1;

    anticlockwise += anti_2;
    anticlockwise += anti_1;
    for(int i = 0; i < s1.size() - 2; i++) {
      anticlockwise += s1[i];
    }
    cout << (s2 == clockwise || s2 == anticlockwise) << endl;
  }
}
