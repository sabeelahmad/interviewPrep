#include<bits/stdc++.h>
using namespace std;

// without map to save space, we can simply push index on stack and then access arr[s.top()]
// instead of saving to map

int main()
 {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    long arr[n];
	    for(int i = 0; i < n; i++) {
	        cin >> arr[i];
	    }
     stack<long> s;
      long ans[n];
      s.push(0);
      for(int i = 1; i < n; i++) {
          if(s.empty()) {
              s.push(i);
              continue;
          }
          while(!s.empty() && arr[s.top()] < arr[i]) {
              ans[s.top()] = arr[i];
              s.pop();
          }
          s.push(i);
      }
      while(!s.empty()) {
          ans[s.top()] = -1;
          s.pop();
      }
      for(int i = 0; i < n; i++) {
          cout << ans[i] << " ";
      }
  	  cout << endl;
}
	return 0;
}
