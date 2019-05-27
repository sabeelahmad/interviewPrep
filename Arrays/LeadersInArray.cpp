#include <bits/stdc++.h>
using namespace std;

// Question : Find all numbers in array for which no elements on the right are greater than it

void leadersInArray(vector<int> &ip, int n) {
  // Traverse from back and maintain a max if curr number greater than max print and update max
  int max = INT_MIN;
  for (int i = n - 1; i >= 0; i--) {
    if (ip[i] >= max) {
      cout << ip[i] << " ";
      max = ip[i];
    }
  }
}

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    vector<int> ip;
    for(int i = 0; i < n; i++) {
      int temp;
      cin >> temp;
      ip.push_back(temp);
    }
    leadersInArray(ip, n);
    cout << endl;
  }
}
