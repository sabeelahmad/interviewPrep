#include <bits/stdc++.h>
using namespace std;

int KthSmallest(int *arr, int n, int k) {
  int freqs[n + 1] = {0};
  freqs[0] = -1;
  for(int i = 0; i < n; i++) {
    freqs[arr[i]]++;
  }
  for(int i = 0; i < n + 1; i++) {
    //cout << freqs[i] << " ";
    if(freqs[i] > 0) {
      k--;
      if (k == 0) {
        return i;
      }
    }
  }
}


int main() {
  int t;
  cin >> t;
  while(t--) {
    int n, k;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    cin >> k;
    cout << KthSmallest(arr, n, k) << endl;
  }
}
