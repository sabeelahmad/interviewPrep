#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        vector<int> a1, a2;
        cin >> n >> m;
        int t;
        for(int i = 0; i < n; i++) {
            cin >> t;
            a1.push_back(t);
        }
        for(int i = 0; i < m; i++) {
            cin >> t;
            a2.push_back(t);
        }
        
        // we will map frequency of a1 elements
        // iterate on a2 and output a1 elements that many time
        // then just sort the elements not present in a2 and output them as well
        unordered_map<int, int> umap;
        umap.clear();
        for(int i = 0; i < n; i++) {
            umap[a1[i]]++;
        }
        
        vector<int> op;
        for(int i = 0; i < m; i++) {
            int freq = umap[a2[i]];
            for(int j = 0; j < freq; j++) {
                op.push_back(a2[i]);
            }
            // make freq of this element 0
            umap[a2[i]] = 0;
        }
        
        // sort remaining elements
        vector<int> remaining;
        for(int i = 0; i < n; i++) {
            if(umap[a1[i]] > 0) {
                remaining.push_back(a1[i]);
            }
        }
        sort(remaining.begin(), remaining.end());
        for(int i = 0; i < remaining.size(); i++) {
            op.push_back(remaining[i]);
        }
        
        for(int i = 0; i < op.size(); i++) {
            cout << op[i] << " ";
        }
        cout << endl;
    }
}
