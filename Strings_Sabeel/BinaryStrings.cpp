#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	   int n;
     cin >> n;
     string s;
     cin >> s;

     vector<int> indices;
     for(int i = 0; i < n; i++) {
       if(s[i] == '1') {
         indices.push_back(i);
       }
     }

     int k = indices.size();
     int ans = 0;
     for(int i = 0; i < k; i++) {
       ans += k - 1 - i;
     }
     cout << ans << endl;
	}
	return 0;
}
