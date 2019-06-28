#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	   int n;
     cin >> n;
     long long a[n];
     for(int i = 0; i < n; i++) {
       cin >> a[i];
     }
     sort(a, a + n);
     // using triangle inequality that sum of two sides should be greater than the third
     // fix last element as third side and use two pointer technique to get ans
     ll ans = 0;
     for(int i = n - 1; i >= 1; i--) {
       int l = 0, r = i - 1;
       while(l < r) {
         if(a[l] + a[r] < a[i]) {
           ans += r - l;
           r--;
         } else {
           l++;
         }
       }
     }
     cout << ans << endl;
	}
	return 0;
}
