#include<bits/stdc++.h>
using namespace std;

int getMinDiff(int *a, int n, int k) {
  // We will sort the array first, and then for each element
  // try both adding and subtracting k, and then proceed greedily and see which gives us minimum differnce
  // between lowest tower and highest tower
  sort(a, a+n);

  // current answer is simply difference of smalles and longest
  int ans = a[n-1]-a[0];

  // corner cases, add k to small and sub k from big
  int small = a[0] + k;
  int big = a[n-1] - k;
  if(small > big) {
    swap(small, big);
  }

  // traverse middle elements
  for(int i = 1; i < n; i++) {
    // try both possibilities
    int subtract = a[i] - k;
    int add = a[i] + k;

    // if changing current heights doesn't yield better result
    if(subtract >= small || add <= big) {
      continue;
    }

    // if better result, use greedy approach

    if(big - subtract <= add - small) {
      small = subtract;
    } else {
      big = add;
    }
  }
  return min(ans, big - small);
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

    cout << getMinDiff(a, n, k) << endl;
	}
	return 0;
}
