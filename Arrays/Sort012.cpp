#include <bits/stdc++.h>
using namespace std;

void sort012(int *arr, int n) {
  // we consider 1 as mid element, if 0 occurs we put it on left and 2 on right
  int low = 0, high = n - 1, mid = 0;
  while(low <= high) {
    if (arr[mid] == 0) {
      int temp = arr[mid];
      arr[mid] = arr[low];
      arr[low] = temp;
      low++;
      mid++;
    } else if (arr[mid] == 1) {
      // do nothing
      mid++;
    } else if (arr[mid] == 2) {
      int temp = arr[mid];
      arr[mid] = arr[high];
      arr[high] = temp;
      high--;
      //mid++;
    }
  }
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    sort012(arr, n);
    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
}
