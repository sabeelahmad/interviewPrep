/* Given an array A[] of N positive integers which can contain integers from 1 to N where elements can be repeated or can be absent from the array. Your task is to count frequency of all elements from 1 to N.

Note: Expected time complexity is O(n) with O(1) extra space. */

/* Since extra space allowed is O(1), we cannot use an extra array to count occurences of elements
rather, we will use values of elements as indices, since numbers are in range 1 To N.
1 = index 0
2 = index 1
3 = index 2
.
.
N = index N - 1

For each number we will add N to the corresponding index, for eg if A[i] = 1, will add N to A[A[i] - 1] : A[0]
Then after the array is processed, all indices will be divided by n, which will give us the number of times N was added at
a particular index, hence the count of the number index + 1 will be A[index] / n
*/

#include <bits/stdc++.h>
using namespace std;

void countFreqsInPlace(int *arr, int n) {
  for(int i = 0; i < n; i++) {
    // Modulo to ensure index in 0 to N - 1
    arr[(arr[i] - 1)%n] = arr[(arr[i] - 1)%n] + n;
  }
  for(int i = 0; i < n; i++) {
    if (arr[i] % n == 0) {
      cout << (arr[i] / n) - 1 << " ";
      continue;
    }
    cout << arr[i] / n << " ";
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
    countFreqsInPlace(arr, n);
    cout << endl;
  }
}
