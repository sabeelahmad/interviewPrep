#include <bits/stdc++.h>
using namespace std;

void subarrayWithSumK(int *arr, int n, int k) {
  // using sliding window technique
  int currsum = arr[0];
  //int windowsum = ;
  int start = 0, end = 0;
  bool flag = false;
  for(int i = 1; i < n; i++) {
    if (currsum == k) {
      flag = true;
      break;
    }
    currsum += arr[i];
    end++;
    if (currsum > k) {
      while(currsum > k) {
        currsum -= arr[start];
        start++;
      }
    }
    //cout << "currsum: " << currsum << " start: " << start << " end: " << end << endl;
  }

  if (currsum > k) {
    while(currsum > k) {
      currsum -= arr[start];
      start++;
    }
  }

  if (currsum == k) {
    flag = true;
  }

  if(!flag) {
    cout << -1 << endl;
  } else {
    cout << start + 1 << " " << end + 1 << endl;
  }
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    subarrayWithSumK(arr, n, k);
    //cout << endl;
  }
}
