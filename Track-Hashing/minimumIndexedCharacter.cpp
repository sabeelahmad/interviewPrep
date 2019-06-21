#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string a, b;
        cin >> a >> b;
        // we create a hash for a and store first occurence of each character of a in it
        // then we traverse b and search for the ans by updating minIndex
        unordered_map<char, int> umap;
        umap.clear();
        int n1 = a.size(), n2 = b.size();
        for(int i = 0; i < n1; i++) {
            if(umap[a[i]] == 0) {
                umap[a[i]] = i + 1;
            }
        }
        int minIdx = INT_MAX;
        for(int i = 0; i < n2; i++) {
            if(umap[b[i]] > 0) {
                if(umap[b[i]] < minIdx) {
                    minIdx = umap[b[i]];
                }
            }
        }
        if(minIdx == INT_MAX) {
            cout << "$" << endl;
        } else {
            cout << a[minIdx - 1] << endl;
        }
    }
}