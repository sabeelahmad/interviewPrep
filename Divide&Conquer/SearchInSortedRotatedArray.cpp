#include<bits/stdc++.h>
using namespace std;

// We can find the ans in one pass of binary search
// We find middle, if key is at middle we return
// Else, either a[l to mid] must be sorted or a[mid + 1 to high] must be
// we find the sorted array and then see within it in what range does key lie and recur
int search(int a[], int low, int high, int key) {
    if(low > high) {
      return -1;
    }

    int mid = (low + high)/2;

    if(a[mid] == key) {
      return mid;
    }

    // if left half sorted
    if(a[low] <= a[mid]) {
      // check in what range key lies and recur
      if(key >= a[low] && key <= a[mid]) {
        return search(a, low, mid - 1, key);
      } else {
        return search(a, mid + 1, high, key);
      }
    }
    // if left half not sorted right half is , check range
    if(key >= a[mid] && key <= a[high]) {
      return search(a, mid + 1, high, key);
    } else {
      return search(a, low, mid - 1, key);
    }
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	 int n;
	 cin >> n;
     int a[n];
     int k;
     for(int i = 0; i < n; i++) {
        cin >> a[i];
     }
     cin >> k;

     int idx = search(a, 0, n - 1, k);
     cout << idx << endl;
	}
	return 0;
}
