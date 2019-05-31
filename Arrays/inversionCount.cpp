#include <bits/stdc++.h>
using namespace std;

long long merge(long long *arr, int si, int ei) {
  long long ic = 0;
  int size = ei - si + 1;
  int mid = (si + ei) / 2;
  int out[size];
  int i = si, j = mid + 1, k = 0;
  while(i <= mid && j <= ei) {
    if(arr[i] <= arr[j]) {
      out[k] = arr[i];
      i++;
      k++;
    } else {
      out[k] = arr[j];
      j++;
      k++;
      ic = ic + (mid - i + 1);
    }
  }
  while(i <= mid) {
    out[k] = arr[i];
    i++;
    k++;
  }
  while(j <= ei) {
    out[k] = arr[j];
    j++;
    k++;
  }
  int m = 0;
  for(int i = si; i <= ei; i++) {
    arr[i] = out[m];
    m++;
  }
  //cout << "ic is : " << ic << endl;
  return ic;
}

long long merge_sort(long long *arr, int si, int ei) {

  long long ic = 0;
  if(si < ei) {
    int mid = (si + ei) / 2;
    ic += merge_sort(arr, si, mid);
    ic += merge_sort(arr, mid + 1, ei);
    ic += merge(arr, si, ei);
  }
  return ic;
}

void mergeSort(long long *arr, int n) {
    cout << merge_sort(arr, 0, n - 1) << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    long long arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    mergeSort(arr, n);
    //for(int i = 0; i < n; i++) cout << arr[i] << " ";
    //cout << endl;
  }
}
