#include <bits/stdc++.h>
using namespace std;

/* Algorithm
   reverse array from 0 to d - 1
   reverse array from d to n - 1
   reverse array from 0 to n - 1
*/

void reverseArray(int *arr, int high, int low) {
  while(high < low) {
    int temp = arr[high];
    arr[high] = arr[low];
    arr[low] = temp;
    high++;
    low--;
  }
}

void rotateArray(int *arr, int d, int n) {
  reverseArray(arr, 0, d - 1);
  reverseArray(arr, d, n - 1);
  reverseArray(arr, 0, n - 1);
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    int n, d;
    cin >> n;
    cin >> d;
    int arr[n];
    for(int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    rotateArray(arr, d, n);
    for(int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
}
