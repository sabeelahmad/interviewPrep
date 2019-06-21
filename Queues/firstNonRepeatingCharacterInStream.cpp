#include <bits/stdc++.h>
using namespace std;

void printNonReptInStream(char * arr, int n) {
  // we create a freq array
  // push each character to queue and increase freq
  // if front of queue freq is 1 it is ans, else we pop it
  // if q empty ans -1
  int freq[26] = {0};
  queue<char> q;
  for(int i = 0; i < n; i++) {
    q.push(arr[i]);
    freq[arr[i] - 'a']++;
    // get first non rept character for current
    while(!q.empty()) {
      if(freq[q.front() - 'a'] == 1) {
        cout << q.front() << " ";
        break;
      } else {
        q.pop();
      }
    }
    if(q.empty()) {
      cout << -1 << " ";
    }
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    char * arr = new char[n];
    for(int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    printNonReptInStream(arr, n);
    delete [] arr;
  }
}
