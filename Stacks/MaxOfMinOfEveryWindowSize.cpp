#include<bits/stdc++.h>
using namespace std;

void printMaxofMin(int* a, int n) {
  stack<int> s;
  int left[n+1];
  int right[n+1];
  // for each element we calculate immediate smaller elements to it on its left and right
  // init
  for(int i = 0; i < n; i++) {
    left[i] = -1;
    right[i] = n;
  }
  // fill left
  for(int i = 0; i < n; i++) {
    while(!s.empty() && a[s.top()] >= a[i]) {
      s.pop();
    }
    if(!s.empty()) {
      left[i] = s.top();
    }
    s.push(i);
  }
  // empty stack
  while(!s.empty()) s.pop();
  // fill right
  for(int i = n-1; i >= 0; i--) {
    while(!s.empty() && a[s.top()] >= a[i]) {
      s.pop();
    }
    if(!s.empty()) {
      right[i] = s.top();
    }
    s.push(i);
  }
  // create ans array
  int ans[n+1] =  {0};
  // fill it
  for(int i = 0; i < n; i++) {
    int len = right[i] - left[i] - 1;
    ans[len] = max(ans[len], a[i]);
  }
  // fill zero entries
  for(int i = n - 1; i >= 0; i--) {
    ans[i] = max(ans[i], ans[i+1]);
  }
  // print
  for(int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
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
     printMaxofMin(a, n);
	}
	return 0;
}
