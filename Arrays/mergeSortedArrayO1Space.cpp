/*
Given two sorted arrays, we need to merge them in O((n+m)*log(n+m)) time with O(1) extra space into a sorted array,
when n is the size of the first array, and m is the size of the second array.
*/

// We can do in constant space and O(n*m) time but reqd tc is less than that

// Idea : Rather than comparing adjacent elements, we compare elements at gap intervals
// Where gap is ciel[(m+n)/2], and after each pass it decreases by 2

// 3 cases: compare in left array, compare in both, compare in right
#include <bits/stdc++.h>
using namespace std;

int nextGap(int gap) {
    if(gap <= 1) {
        return 0;
    }
    return (gap/2) + (gap%2);
}

void mergeO1(int *a1, int *a2, int n, int m) {
  int i, j, gap = n + m;
  for(gap = nextGap(gap); gap > 0; gap = nextGap(gap)) {
    // compare in first array
    for(i = 0; i + gap < n; i++) {
      if(a1[i] > a1[i + gap]) {
        swap(a1[i], a1[i + gap]);
      }
    }
    // calculate where from to start in second array
    if (gap > n) {
      j = gap - n;
    } else {
      j = 0;
    }
    // compare in first and second array
    for(; i < n && j < m; i++, j++) {
      if(a1[i] > a2[j]) {
        swap(a1[i], a2[j]);
      }
    }
    // compare in second array
    if (j < m) {
      for(j = 0; j + gap < m; j++) {
        if(a2[j] > a2[j + gap]) {
          swap(a2[j], a2[j + gap]);
        }
      }
    }
  }
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n, m;
    cin >> n >> m;
    int a1[n];
    int a2[m];
    for(int i = 0; i < n; i++) {
      cin >> a1[i];
    }
    for(int i = 0; i < m; i++) {
      cin >> a2[i];
    }
    mergeO1(a1, a2, n, m);
    for(int i = 0; i < n; i++) {
      cout << a1[i] << " ";
    }
    for(int i = 0; i < m; i++) {
      cout << a2[i] << " ";
    }
    cout << endl;
  }
}
