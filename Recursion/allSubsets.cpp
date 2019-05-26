#include <bits/stdc++.h>
using namespace std;

void printSubset(vector<int> &currentSubset) {
  if (currentSubset.size() == 0) cout << "EMPTY SET";
  for(int i = 0; i < currentSubset.size(); i++) {
    cout << currentSubset[i] << " ";
  }
  cout << endl;
}

void printAllSubsetsHelper(int *arr, int n, vector<int> &currentSubset) {
  // The logic is that either element will be included in subset or not
  if (n == 0) {
    printSubset(currentSubset);
    return;
  }
  // Include current number
  currentSubset.push_back(arr[0]);
  printAllSubsetsHelper(arr + 1, n - 1, currentSubset);
  // Exclude current number
  currentSubset.pop_back();
  printAllSubsetsHelper(arr + 1, n - 1, currentSubset);
}

void printAllSubsets(int *arr, int n) {
  vector<int> currentSubset;
  printAllSubsetsHelper(arr, n, currentSubset);
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
    printAllSubsets(arr, n);
    //cout << endl;
  }
  return 0;
}
