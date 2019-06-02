#include <bits/stdc++.h>
using namespace std;

// int merge(double *a1, double *a2, int n, int m) {
//   // no need to actually merge just count inversions
//   int i = 0, j = 0;
//   int ic = 0;
//   while(i < n && j < m) {
//     if(a1[i] <= a2[j]) {
//       i++;
//     } else {
//       ic += n - i;
//       j++;
//     }
//   }
//   return ic;
// }


void countPairs(double *a1, double *a2, int n, int m) {
  // use logx/x > logy/y
  for(int i = 0; i < n; i++) {
    a1[i] = log(a1[i]) / a1[i];
  }
  for(int i = 0; i < m; i++) {
    a2[i] = log(a2[i]) / a2[i];
  }
  // sort
  sort(a1, a1+n);
  sort(a2, a2+m);
  // now merge the two sorted arrays and count inversions to get ans
  //ic = merge(a1, a2, n, m);
  int ic = 0;
  // rather tan counting inversions we can use lower bound func of stl
  // lower bound tells posn of element in an array that is equal to given element
  // if element not found it gives posn just greater than element
  // this can be used, we can search is logx/x in a2 and get the no of elements smaller than it
  for(int i = 0; i < n; i++) {
    int x = lower_bound(a2, a2+m, a1[i]) - a2; // subtracting b to get index, else it returns iterator
    ic+= x;
  }
  cout << ic << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    int n, m;
    cin >> n >> m;
    double a1[n], a2[m];
    for(int i = 0; i < n; i++) {
      cin >> a1[i];
    }
    for(int i = 0; i < m; i++) {
      cin >> a2[i];
    }
    countPairs(a1, a2, n, m);
  }
}
