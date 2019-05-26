#include <bits/stdc++.h>
using namespace std;

void printSubsetSumToKHelper(int *arr, int n, int k, vector<int> &currentSubset) {
  if (k < 0) {
    // ignore subset
    return;
  }
  if (k == 0) {
    // subset found
    for (int i = 0; i < currentSubset.size(); i++) {
      cout << currentSubset[i] << " ";
    }
    cout << endl;
    return;
  }
  if (n == 0) {
    if (k == 0) {
      for (int i = 0; i < currentSubset.size(); i++) {
        cout << currentSubset[i] << " ";
      }
      cout << endl;
    }
    return;
  }
  // call on subset
  // include current number
  currentSubset.push_back(arr[0]);
  printSubsetSumToKHelper(arr + 1, n - 1, k - arr[0], currentSubset);
  // dont include current number
  currentSubset.pop_back();
  printSubsetSumToKHelper(arr + 1, n - 1, k, currentSubset);
}

void printSubsetSumToK(int *arr, int n, int k) {
  vector<int> currentSubset;
  printSubsetSumToKHelper(arr, n, k, currentSubset);
}

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    int k;
    cin >> k;
    printSubsetSumToK(arr, n, k);
    cout << endl;
  }
  return 0;
}
