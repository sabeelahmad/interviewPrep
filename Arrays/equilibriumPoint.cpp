/*
  Given an array A of N positive numbers. The task is to find the position where equilibrium first occurs in the array.
  Equilibrium position in an array is a position such that the sum of elements before it is equal to the sum of elements after it.
*/

// Using prefix sum technique to solve

#include <bits/stdc++.h>
using namespace std;

int getEqbPt(long long *arr, int n) {
  // Calculate prefix sum
  long long prefixsum[n] = {0};

  for(int i = 0; i < n; i++) {
    if (i == 0) {
      prefixsum[i] = arr[i];
    } else {
      prefixsum[i] = prefixsum[i - 1] + arr[i];
    }
  }

  for(int i = 0; i < n; i++) {
    int lsum, rsum;
    if (i == 0) {
      lsum = 0;
      rsum = prefixsum[n - 1] - prefixsum[i];
    }
    else if (i == n - 1) {
      rsum = 0;
      lsum = prefixsum[i - 1];
    }
    else {
      lsum = prefixsum[i - 1];
      rsum = prefixsum[n - 1] - prefixsum[i];
    }
    if (lsum == rsum) {
      return i + 1;
    }
  }
  return -1;
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    cout << getEqbPt(arr, n) << endl;
  }
}
