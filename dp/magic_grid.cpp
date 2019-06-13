#include <bits/stdc++.h>
using namespace std;

int magic_grid(int ** input, int si, int sj, int ei, int ej) {
  // Base case 1 : final dest reached
  if(si == ei && sj == ej) {
    // min health required is 1 not 0
    return 1;
  } 
  // Avoid going out of grid
  if(si > ei || sj > ej) {
    return INT_MAX;
  }
  // can go down or right
  // recursively call on both get min health from those and subtract val from those
  // take care the current health shouldnt become <= 0 if it does make it 1
  int option1 = magic_grid(input, si, sj + 1, ei, ej) - input[si][sj + 1];
  int option2 = magic_grid(input, si + 1, sj, ei, ej) - input[si + 1][sj];
  if(option1 <= 0) {
    option1 = 1;
  }
  if(option2 <= 0) {
   option2 = 1;
  }
  return min(option1, option2);
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int m, n;
    cin >> m >> n;
    int ** input = new int*[n];
    for(int i = 0; i < m; i++) {
      input[i] = new int[n];
    }
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
        cin >> input[i][j];
      }
    }
    cout << magic_grid(input, 0, 0, m - 1, n - 1) << endl;
  }
}
