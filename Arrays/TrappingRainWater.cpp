#include <bits/stdc++.h>
using namespace std;

int trapRainWater(int *arr, int n) {
  // array for left max for each element
  int leftMax[n];
  leftMax[0] = 0;
  int lmax = arr[0];
  for(int i = 1; i < n; i++) {
    lmax = max(lmax, arr[i - 1]);
    leftMax[i] = lmax;
  }
  // array for right max for each element
  int rightMax[n];
  rightMax[n - 1] = 0;
  int rmax = arr[n - 1];
  for(int i = n - 2; i >= 0; i--) {
    rmax = max(rmax, arr[i + 1]);
    rightMax[i] = rmax;
  }
  int waterTrappedSum = 0;
  for (int i = 1; i < n - 1; i++) {
    int p = min(leftMax[i], rightMax[i]) - arr[i];
    if (p < 0) {
      continue;
    } else {
      waterTrappedSum += p;
    }
  }
  return (waterTrappedSum > 0) ? waterTrappedSum : 0;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    cout << trapRainWater(arr, n) << endl;
  }
}
