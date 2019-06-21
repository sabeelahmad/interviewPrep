#include <bits/stdc++.h>
using namespace std;

void printKMax(int* a, int n, int k) {
  deque<int> Q(k); // we keep it sorted in decreasing order and stores only useful

  // process first k
  int i;
  for(i = 0; i < k; i++) {
    // remove all items smaller than a[i] from deque at rear
    while((!Q.empty()) && a[i] >= a[Q.back()]) {
      Q.pop_back();
    }
    // push in deque at back
    Q.push_back(i);
  }

  // process rest of elements
  for(; i < n; i++) {
    // output max for current window
    cout << a[Q.front()] << " ";

    // remove elements not part of window anymore
    while(!(Q.empty()) && Q.front() <= i - k) {
      Q.pop_front();
    }

    // remove elements less than new element of window
    while((!Q.empty()) && a[i] >= a[Q.back()]) {
      Q.pop_back();
    }

    // add new element at rear
    Q.push_back(i);
  }

  // print for last window
  cout << a[Q.front()] << endl;
}


int main() {
  int t;
  cin >> t;
  while(t--) {
    int n, k;
    cin >> n >> k;
    int * a = new int[n];
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    printKMax(a, n, k);
  }
}
