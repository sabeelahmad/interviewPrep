#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    long long x;
	    cin >> n >> x;
	    vector<long long> v;
	    for(int i = 0; i < n; i++) {
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    // we can use lower_bound to get the first element in the array that
	    // is greater than x
	    vector<long long>::iterator idx;
	    idx = lower_bound(v.begin(), v.end(), x);
	    int idx2 = idx - v.begin();
	    if(idx2 == 0 && v[0] != x) {
	        cout << -1 << endl;
	    } else if(idx2 < n && v[idx2] == x) {
	        cout << idx2 << endl;
	    } else {
	        cout << idx2 - 1 << endl;
	    }
	}
	return 0;
}
