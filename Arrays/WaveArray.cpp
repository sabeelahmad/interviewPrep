#include <bits/stdc++.h>
using namespace std;

// ***Given array is Sorted

// Rather than swapping at each index, we can do pairwise swaps

void convertToWave(int *arr, int n) {
  for(int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      // if index even
      // even index val should be greater than its adjacent odd index
      if (arr[i] < arr[i + 1] && i + 1 < n) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
      }
    } else {
      // if index odd
      // odd index val should be less than its adjacent even index
      if (arr[i] > arr[i + 1] && i + 1 < n) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
      }
    }
  }
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
    convertToWave(arr, n);
    for(int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
}
