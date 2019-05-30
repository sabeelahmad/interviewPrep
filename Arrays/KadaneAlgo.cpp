/*
  Find Maximum Sum Subarray (contiguous)
*/

#include <bits/stdc++.h>
using namespace std;

// The algo is simple if the sum at any point becomes less than 0, we break the subarray, and start calculating a new Subarray
// if all nos are negative, the maximum element is the answer

int kadane(int *arr, int n) {
  int maxSoFar = INT_MIN; // maxsum
  int maxEndingHere = 0; // currsum

  for(int i = 0; i < n; i++) {
    maxEndingHere += arr[i];
    if (maxSoFar < maxEndingHere) {
      maxSoFar = maxEndingHere;
    }
    if (maxEndingHere < 0) {
      maxEndingHere = 0;
    }
  }
  return maxSoFar;
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    cout << kadane(arr, n) << endl;
  }
}
