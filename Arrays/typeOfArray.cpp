#include <bits/stdc++.h>
#define ll long long int
using namespace std;

/*
You are given an array of size N having no duplicate elements. The array can be categorized into following:
1.  Ascending
2.  Descending
3.  Descending Rotated
4.  Ascending Rotated
Your task is to print which type of array it is and the maximum element of that array.
*/

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    ll minx = INT_MAX, maxx = INT_MIN;
    for(int i = 0; i < n; i++) {
      minx = min(minx, a[i]);
      maxx = max(maxx, a[i]);
    }

    // if min = first element and max = last element, Ascending order
    if(minx == a[0] && maxx == a[n - 1]) {
      cout << maxx << " " << 1 << endl;
    }
    // if min == last and max = first, Descending order
    else if (minx == a[n - 1] && maxx == a[0]) {
      cout << maxx << " " << 2 << endl;
    }
    // if neither of the above, we check if last element is greater than first element, if yes than array was Descending and has been rotated
    else if(a[n - 1] > a[0]) {
      cout << maxx << " " << 3 << endl;
    } else {
      // if none of the above then ascending rotated
      cout << maxx << " " << 4 << endl;
    }
  }
}
