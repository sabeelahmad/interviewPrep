// logic is simple, we use the logic of max 0 sum subarray
// we maintain prefix sum, if same sum has been seen before we increment ans
// also if sum is 0 we increment  ans then as well
// in hash we store how many times a sum has been seen before , because that will be the amount of increment in ans if same sum is seen later

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	   int n;
     cin >> n;
     ll a[n];
     for(int i = 0; i < n; i++) {
       cin >> a[i];
     }
     unordered_map<int, int> umap;
     umap.clear();
     int sum = 0;
     int ans = 0;
     for(int i = 0; i < n; i++) {
       sum += a[i];

       // if sum 0, we have a subarray
       if(sum == 0) {
         ans++;
       }
       // also check if same sum, 0 or not is seen before, if seen check how many times
       if(umap.find(sum) != umap.end()) {
         ans += umap[sum];
       }
       // increment count of how many times sum is seen in hahs
       umap[sum]++;
     }
     cout << ans << endl;
	}
	return 0;
}
