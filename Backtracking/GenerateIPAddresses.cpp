#include <bits/stdc++.h>
using namespace std;

bool isValidIP(int a, int b, int c, int d) {
  return (a <= 255 && b <= 255 && c <= 255 && d <= 255);
}

string generateIPString(int a, int b, int c, int d) {
  return to_string(a) + "." + to_string(b) + "." + to_string(c) + "." + to_string(d);
}

vector <string> genIp(string s) {
    // vector to hold all ips generated
    vector <string> res;
    // rather than using backtracking, we will use naive approach and consider substrings(4 in number)
    for(int i = 1; i <=3; i++) {
      for(int j = 1; j <= 3; j++) {
        for(int k = 1; k <= 3; k++) {
          for(int l = 1; l <= 3; l++) {
            // check if we are not overshooting length
            if(i + j + k + l == s.size()) {
              // get int values of each part of ip add in consideration right now
              int a = stoi(s.substr(0, i));
              int b = stoi(s.substr(i, j));
              int c = stoi(s.substr(i+j, k));
              int d = stoi(s.substr(i+j+k, l));
              // check validity of this ip add
              if(isValidIP(a, b, c, d)) {
                // get ip string
                string ip = generateIPString(a, b, c, d);
                // add to res
                if(ip.length() == s.length() + 3) {
                  res.push_back(ip);
                }
              }
            }
          }
        }
      }
    }

    return res;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    string s;
    cin >> s;
    vector <string> ips = genIp(s);
    cout << ips.size() << endl;
  }
}
