#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    ll a[n], b[n];
	    for(int i = 0; i < n; i++) {
	        cin >> a[i];
	    }
	    for(int i = 0; i < n; i++) {
	        cin >> b[i];
	    }
	    unordered_map<int, int> umap;
	    umap.clear();
	    for(int i = 0; i < n; i++) {
	        umap[a[i]]++;
	    }
	    unordered_map<int, int> umap2;
	    umap2.clear();
	    for(int i = 0; i < n; i++) {
	        umap2[b[i]]++;
	    }
	    bool ans = true;
	    for(int i = 0; i < n; i++) {
	        if(umap[a[i]] != umap2[a[i]]) {
	            cout << 0 << endl;
	            ans = false;
	            break;
	        }
	    }
	    if(ans) {
	        cout << 1 << endl;
	    }
	}
	return 0;
}