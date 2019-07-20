#include <bits/stdc++.h>
using namespace std;

pair<int, int> getRange(int a[], int n) {
  pair<int, int> x;
  x.first = INT_MIN;
  x.second = 0;
  for(int i = 0; i < n; i++) {
    x.first = max(a[i], x.first);
    x.second += a[i];
  }
  return x;
}

int paintersRequired(int a[], int n, int maxLen) {
  int total = 0, num = 1;
  // we add to total till it is less than the mid currently, if it becomes greater we add a painter
  for(int i = 0; i < n; i++) {
    total += a[i];
    if(total > maxLen) {
      num++;
      // reinit total for next painter
      total = a[i];
    }
  }
  return num;
}

int painters(int a[], int n, int k) {
  // We establish the range from Max element in array (in case one painter is alloted only one board) to sum of array(in case 1 painter alone does word)
  pair<int, int> t = getRange(a, n);
  int low = t.first, high = t.second;

  // Now that the range has been established, our job is to bring lo and high as close as possible, we achieve this using binary search
  while(low < high) {
    // get mid
    int mid = (low + high) / 2;
    // find how many painters will be required to paint board of mid len
    int p = paintersRequired(a, n, mid);
    // if number of painters required in time mid is less than k we can close the gap even more
    if(p <= k) {
      high = mid;
    } else {
      // else we need to increase the range so painters required remain within k
      low = mid + 1;
    }
  }
  return low;
}


int main() {
  int t;
  cin >> t;
  while(t--) {
    int k, n;
    cin >> k >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    cout << painters(a, n, k) << endl;
  }
}
