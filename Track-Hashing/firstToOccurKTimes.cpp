#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> v;

        for(int i = 0; i < n; i++) {
            int t;
            cin >> t;
            v.push_back(t);
        }

        unordered_map<int, int> umap;
        umap.clear();
        
        for(int i = 0; i < n; i++) {
            umap[v[i]]++;
        }

        bool isAns = false;
        for(int i = 0; i < n; i++) {
            if(umap[v[i]] == k) {
                cout << v[i] << endl;
                isAns = true;
                break;
            }
        }
        if(!isAns) {
            cout << -1 << endl;
        }
    }
}