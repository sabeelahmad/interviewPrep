#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	   int n, k;
     cin >> n >> k;
     int a[n];
     for(int i = 0; i < n; i++) {
       cin >> a[i];
     }
     int sum[n];
     sort(a, a+n);
     sum[0]=a[0];
     for(int i=1;i<n;i++){
        sum[i]=a[i]+sum[i-1];
      }
     int ans = INT_MAX, temp = 0;
     for(int i = 0; i < n; i++) {
       for(int j = n - 1; j > i; j--) {
         if(a[j] - a[i] <= k) {
           break;
         }
         temp += a[j] - a[i] - k;
       }
       ans = min(ans, temp);
       temp = sum[i];
     }
     cout << ans << endl;
	}
	return 0;
}
