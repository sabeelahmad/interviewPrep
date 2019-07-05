#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	   int n, k;
     cin >> n >> k;
     int prices[n];
     for(int i = 0; i < n; i++) {
       cin >> prices[i];
     }
     // To get min cost, we pick leftmost from sorted array and get right most k for free and do opposite for maxcost

     // sort
     sort(prices, prices + n);
     int l = 0, r = n - 1;
     int min_cost = 0, max_cost = 0, candies = 0;
     while(l <= r) {
       min_cost += prices[l];
       l++;
       r -= k;
       //candies += 1 + k;
     }
     l = 0, r = n - 1, candies = 0;
     while(l <= r) {
       max_cost += prices[r];
       l += k;
       r--;
       //candies += 1 + k;
     }
     cout << min_cost << " " << max_cost << endl;
	}
	return 0;
}
