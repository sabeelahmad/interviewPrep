#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    queue<int> q;
    // we use a queue to rotate cards, and array to store positoning
    for(int i = 0; i < n; i++) {
      q.push(i);
    }
    int arr[n]={0};
    for(int i = 1; i <= n; i++) {
      // move first i elements to back
      for(int j = 1; j <= i; j++) {
        q.push(q.front());
        q.pop();
      }
      arr[q.front()] = i;
      q.pop();
    }

    for(int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
}
