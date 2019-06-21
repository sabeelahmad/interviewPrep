#include <bits/stdc++.h>
using namespace std;

// we can do using hashing also
// for each element check if it is start pt of a subsequence or not, if not, check all consec nos after it and update ans

int LongestConsecutiveSubsequence(int a[], int n)
{
   sort(a, a + n);
   if(n == 1) {
        return 1;
   }
   // for(int i = 0; i < n; i++) {
   //   cout << a[i] << " ";
   // }
   // cout << endl;
   long long ans = 1, ans2 = INT_MIN;
   for(int i = 1; i < n; i++) {
       if(a[i - 1] + 1 == a[i]) {
           ans++;
       } else {
           ans2 = max(ans2, ans);
           ans = 1;
       }
       //cout << a[i] << " " << ans << " " << ans2 << endl;
   }
   // check after coming out once if ans2 is greater than ans
   return max(ans2, ans);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << LongestConsecutiveSubsequence(a, n) << endl;
    }
}
