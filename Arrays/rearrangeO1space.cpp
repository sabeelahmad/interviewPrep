#include <bits/stdc++.h>
using namespace std;

/* To rearrange in O(1) space, we create a max element that is greater than the max in given array
  Then we traverse from l to r, and if i is even, we add arr[max_index]%max_elem * max_elem to given no
  if odd we add arr[min_index]%max_elem * max_elem to given no
  to retrieve the nos changed form we simply divide all numbers by max_elem
*/

void rearrange(int *arr, int n) {
  int max_index = n - 1, min_index = 0, max_element = arr[n - 1] + 1;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      arr[i] += (arr[max_index] % max_element) * max_element;
      max_index--;
    } else {
      arr[i] += (arr[min_index] % max_element) * max_element;
      min_index++;
    }
  }
  for(int i = 0; i < n; i++) {
    arr[i] = arr[i] / max_element;
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
    rearrange(arr, n);
    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
}
