#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t;
	cin >> t;
	while(t--) {
	    long long n;
	    cin >> n;
	    if(n == 1) {
	        cout << "YES" << endl;
	        continue;
	    }
	    float x = log2(n);
	    //cout << x << endl;
	    if(x == floor(x)) {
	        cout << "YES" << endl;
	    } else {
	        cout << "NO" << endl;
	    }
	}
	return 0;
}
