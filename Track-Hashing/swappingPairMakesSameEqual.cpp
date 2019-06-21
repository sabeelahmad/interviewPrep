#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	    for(int i = 0; i < n; i++) {
	        cin >> a[i];
	    }
	    for(int i = 0; i < m; i++) {
	        cin >> b[i];
	    }
	    int sum1 = 0, sum2 = 0;
	    for(int i = 0; i < n; i++) sum1+=a[i];
	    for(int i = 0; i < m; i++) sum2+=b[i];
	    int diff;
	    if(sum1 > sum2) {
	        diff = (sum1 - sum2) / 2;
	    } else {
	        diff = (sum2 - sum1) / 2;
	    }
	    
	    // we are looking for two nos such that
	    // sumA - a + b = sumB - b + a
	    // a - b = (sumA - sumB) / 2
	    // or a = b + diff
	    // we create a hash for smaller array, and while traversing larger one search for b + diff in hash of smaller, if we get it, ans is true
	    unordered_map<int , bool> umap;
	    bool ans = false;
	    umap.clear();
	    if(n < m) {
	        // hash a
	        for(int i = 0; i < n; i++) {
	            umap[a[i]] = true;
	        }
	        // now traverse b and search for a number in b such that b[i] + diff is in hash of a
	        for(int i = 0; i < m; i++) {
	            if(umap[b[i] + diff]) {
	                ans = true;
	                break;
	            }
	        }
	    } else {
	        // hash b
	        for(int i = 0; i < m; i++) {
	            umap[b[i]] = true;
	        }
	        // traverse a and search for a[i] + diff to be in hash of b
	        for(int i = 0; i < n; i++) {
	            if(umap[a[i] + diff]) {
	                ans = true;
	                break;
	            }
	        }
	    }
	    
	    if(!ans) {
	        cout << -1 << endl;
	    } else {
	        cout << 1 << endl;
	    }
	}
	return 0;
}