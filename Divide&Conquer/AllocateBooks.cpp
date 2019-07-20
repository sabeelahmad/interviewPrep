#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

ll countStudents(ll books[], ll n, ll mid) {
    ll total = 0, num = 1;
    for(int i = 0; i < n; i++) {
        total += books[i];
        // if total exceeds mid, add student
        if(total > mid) {
            total = books[i];
            num++;
        }
    }
    return num;
}

// Same logic as painters partition
ll allocateBooks(ll books[], ll n, ll m) {
    if(n < m) return -1;
    // Get sum and max of array to establish range
    ll s = INT_MIN, total_pages = 0;
    for(int i = 0; i < n; i++) {
        total_pages += books[i];
        s = max(s, books[i]);
    }
    ll e = total_pages;
    cout << s << " " << e << endl;
    while(s < e) {
        // mid
        ll mid = (s + e) / 2;
        cout << s << " " << e << " " << mid << " " << endl;
        // check how many students required for mid pages
        if(countStudents(books, n, mid) <= m) {
            // if valid, check for more lower ans
            e = mid;
        } else {
            // if not valid, check for upper ans
            s = mid + 1;
        }
    }
    return s;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    ll n;
	    cin >> n;
	    ll books[n];
	    for(int i = 0; i < n; i++) {
	        cin >> books[i];
	    }
	    ll m;
	    cin >> m;
	    cout << allocateBooks(books, n, m) << endl;
	}
	return 0;
}
