// The cost of stock on each day is given in an array A[] of size N.
// Find all the days on which you buy and sell the stock so that in between those days your profit is maximum.

// We will create a local minima and maxima table, we will buy stocks on minima and sell on maxima

#include <bits/stdc++.h>
using namespace std;

void stockBuyAndSell(int *arr, int n) {
  vector<int> minima, maxima;
  for (int i = 0; i < n; i++) {
    // i = 0 and i = n - 1 are edge case, we shouldnt go out of bound
    if (i == 0 && arr[i + 1] > arr[i]) {
      minima.push_back(i);
    }
    if (i == n - 1 && arr[i - 1] < arr[i]) {
      maxima.push_back(i);
    }
    if (i != 0 && i != n - 1 && arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
      minima.push_back(i);
    }
    if (i != 0 && i != n - 1 && arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
      maxima.push_back(i);
    }
  }

  if (minima.size() == 0 || maxima.size() == 0) {
    cout << "No Profit";
    return;
  }

  for (int i = 0; i < minima.size() && i < maxima.size(); i++) {
    cout << "(" << minima[i] << " " << maxima[i] << ") ";
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
    stockBuyAndSell(arr, n);
    cout << endl;
  }
}
