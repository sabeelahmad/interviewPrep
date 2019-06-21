#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < m; i++) {
            cin >> b[i];
        }
        if(m > n) {
            cout << "No" << endl;
            continue;
        }
        // we have to check whether b is subset of a
        // we simply create hash of a, and for b we see if each element is present in hash of a
        // duplicates are not present in arrays as mentioned in question
        unordered_map<int, int> umap;
        umap.clear();
        for(int i = 0; i < n; i++) {
            umap[a[i]]++;
        }
        bool ans = true;
        for(int i = 0; i < m; i++) {
            if(umap[b[i]] == 0) {
                ans = false;
                break;
            }
        }
        if(ans) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}