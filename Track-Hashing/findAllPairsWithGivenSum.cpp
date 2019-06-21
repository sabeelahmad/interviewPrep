#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        int a[n], b[m];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < m; i++) {
            cin >> b[i];
        }
        // we have to find cross pairs in the two arrays that sum to k
        // we will hash array b and traverse array a and search for k - a[i] in the hash of b
        unordered_map<int, int> umap;
        umap.clear();
        for(int i = 0; i < m; i++) {
            umap[b[i]]++;
        }
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++) {
            if(umap[k - a[i]] > 0) {
                v.push_back(make_pair(a[i], k - a[i]));
            }
        }
        if(v.size() == 0) {
            cout << -1 << endl;
        } else {
            sort(v.begin(), v.end());
            for(int i = 0; i < v.size(); i++) {
                cout << v[i].first << " " << v[i].second;
                if(i != v.size() - 1) {
                    cout << ", ";
                } else {
                    cout << endl;
                }
            }
        }
    }
}