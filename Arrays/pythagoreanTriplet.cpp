#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    int a[n];
	    for(int i = 0; i < n; i++) {
	        cin >> a[i];
	        a[i] = a[i]*a[i];
	    }
	    sort(a, a+n);
	   // fix last element as a, and find a pair such that their sum is a
	   int idx = n - 1;
	   bool ans = false;
	   while(!ans) {
	       int x = a[idx];
	       for(int i = 0, j = idx - 1; i < j;) {
	           if(a[i] + a[j] == x) {
	               ans = true;
	               break;
	           } else if (a[i] + a[j] < x) {
	               i++;
	           } else if(a[i] + a[j] > x) {
	               j--;
	           }
	       }
	       idx--;
	       if(idx < 0) {
	           break;
	       }
	   }
	   if(!ans) {
	       cout << "No" << endl;
	   } else {
	       cout << "Yes" << endl;
	   }
	}
	return 0;
}
