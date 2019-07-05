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
	        cin >>  a[i];
	    }
	    // we calculate cumulative sum
	    // if sum is seen for first time add to hash
	    // if sum is k, maxlen update
	    // also if sum - k is present update maxlen
	    int maxlen = 0, sum = 0;
	    unordered_map<int, int> umap;
	    umap.clear();
	    for(int i = 0; i < n; i++) {
	        sum += a[i];
	        if(sum == k) {
	            maxlen = i + 1;
	        }
	        if(umap.find(sum) == umap.end()) {
	            umap[sum] = i;
	        }
	        if(umap.find(sum - k) != umap.end()) {
	            if(maxlen < i - umap[sum - k]) {
	                maxlen = i - umap[sum - k];
	            }
	        }
	    }
	    cout << maxlen << endl;
	}
	return 0;
}
