#include <bits/stdc++.h>
using namespace std;


bool isDivisble(string n, string currentPerm) {
  //cout << n << " " << currentPerm;
  if(n.lenght() == 1) {
    currentPerm += n;
    int x = stoi(currentPerm);
    if(x % 8 == 0) {
      return true;
    }
  }

  for(int i = 0; i < n.size(); i++) {
    char temp = n[0];
    n[0] = n[i];
    n[i] = temp;

    string temp2 = currentPerm;
    temp2 += n[0];
    if(isDivisble(n.substr(1), temp2)) {
      return true;
    }
  }

  return false;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    string n;
    cin >> n;
    if(isDivisble(n, "")) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}
