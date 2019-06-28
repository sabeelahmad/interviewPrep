#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	   string s;
     cin >> s;
     int n, k;
     cin >> k >> n;
     char x;
     cin >> x;
     int l = s.size();
     int blocks = n / l;
     int rem = n % l;
     int cnt = 0;
     for(int i = 0; i < l; i++) {
       if(s[i] == x) {
         cnt++;
       }
     }

     int ans = cnt*blocks;
     if(rem != 0) {
       for(int i = 0; i < rem; i++) {
         if(s[i] == x) ans++;
       }
     }

     cout << ans << endl;
	}
	return 0;
}
