#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n, x;
	    cin >> n >> x;
	    int a[n];
	    for(int i = 0; i < n; i++) {
	        cin >> a[i];
	    }
	    int count = 0;
	    for(int i = 0; i < n; i++) {
	        if(a[i] == x) {
	            count++;
	        }
	        if(a[i] > x) {
	            break;
	        }
	    }
	    if(count == 0) {
	        cout << -1 << endl;
	    } else {
	        cout << count << endl;
	    }
	}
	return 0;
}
