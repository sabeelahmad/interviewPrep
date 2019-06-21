#include <bits/stdc++.h>
using namespace std;

void printSubsetSumToKHelper(int *arr, int n, int k, vector<int> &currentSubset, set< vector<int> > &s) {
  if (k < 0) {
    // ignore subset
    return;
  }
  if (k == 0) {
    // add this subset to set
    //sort(currentSubset.begin(), currentSubset.end());
    s.insert(currentSubset);
    return;
  }
  if (n == 0) {
    if (k == 0) {
      //sort(currentSubset.begin(), currentSubset.end());
      s.insert(currentSubset);
    }
    return;
  }
  // call on subset
  // include current number
  currentSubset.push_back(arr[0]);
  printSubsetSumToKHelper(arr + 1, n - 1, k - arr[0], currentSubset, s);
  // dont include current number
  currentSubset.pop_back();
  printSubsetSumToKHelper(arr + 1, n - 1, k, currentSubset, s);
}

void printSubsetSumToK(int *arr, int n, int k) {
  vector<int> currentSubset;
  set< vector<int> > s;
  printSubsetSumToKHelper(arr, n, k, currentSubset, s);
  if(s.size() == 0) {
    cout << "Empty";
    return;
  }
  for(auto itr = s.begin(); itr != s.end(); itr++) {
    cout << "(";
    for(int i = 0; i < itr->size(); i++) {
      cout << itr->at(i);
      if(i != itr->size() - 1) {
        cout << " ";
      }
    }
    cout << ")";
  }
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
    sort(arr, arr + n);
    int k;
    cin >> k;
    printSubsetSumToK(arr, n, k);
    cout << endl;
  }
  return 0;
}
