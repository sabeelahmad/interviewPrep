#include <bits/stdc++.h>
using namespace std;

vector<long long> reverseArrayInGroupsOfK(vector<long long> mv, int n, int k) {
  for(int i = 0; i < n;) {
        int h = i;
        int l;
        if (i + k - 1 >= n) {
            l = n - 1;
        } else {
            l = i + k - 1;
        }
        while(h < l) {
            long long temp = mv[h];
            mv[h] = mv[l];
            mv[l] = temp;
            h++;
            l--;
        }
        i = i + k;
    }
    return mv;
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    vector<long long> mv;
    for(int i = 0; i < n; i++) {
      long long x;
      cin >> x;
      mv.push_back(x);
    }
    int k;
    cin >> k;
    mv = reverseArrayInGroupsOfK(mv, n, k);
    cout << endl;
    for(int i = 0; i < n; i++) {
      cout << mv[i] << " ";
    }
    cout << endl;
  }
}
