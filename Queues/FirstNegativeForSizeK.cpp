#include<bits/stdc++.h>
using namespace std;

void printNegative(int* a, int n, int k) {
  // we use deque, which stores only useful elements, ie negative elements
  deque<int> q;
  // process first window
  int i;
  for(i = 0; i < k; i++) {
    if(a[i] < 0) {
      q.push_back(i);
    }
  }
  // now for every window we print first element if present , else 0 and also process more
  for(; i < n; i++) {
    if(!q.empty()) {
      cout << a[q.front()] << " ";
    } else {
      cout << 0 << " ";
    }
    // remove element out of window
    while(!q.empty() && q.front() < i-k+1) q.pop_front();
    // check if next element is useful
    if(a[i] < 0) {
      q.push_back(i);
    }
  }
  // print for last window
  if(!q.empty()) cout << a[q.front()] << endl;
  else cout << 0 << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	   int n;
     cin >> n;
     int a[n];
     for(int i = 0; i < n; i++) {
       cin >> a[i];
     }
     int k;
     cin >> k;
     printNegative(a, n, k);
	}
	return 0;
}
