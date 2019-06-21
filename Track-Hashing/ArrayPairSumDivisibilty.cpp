// We will save modulo k of every no and hash it
// the while traversing the modulos, we will search for k - (a[i]%k) in the hash, if we find it, means there is a pair 
// if not found for any no, ans is false, since atleast one no cant be paired with another

#include <bits/stdc++.h>
using namespace std;

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
        int k;
        cin >> k;
        if(n%2 != 0) {
            cout << "False" << endl;
            continue;
        }
        // take modulo of each element
        for(int i = 0; i < n; i++) {
            a[i] = a[i] % k;
        }
        unordered_map<int, int> umap;
        umap.clear();
        // create hash of count of modulos
        for(int i = 0; i < n; i++) {
            umap[a[i]]++;
        }
        // traverse the modulos taken and search for k - modulo in hash
        bool found  = false;
        for(int i = 0; i < n; i++) {
            if(umap[k - a[i]] > 0) {
                // means we have a pair
                // reduce count of both a[i] and k - a[i] in map by 1
                umap[k - a[i]]--;
                umap[a[i]]--;
                found = true;
            } else {
                // not found ans is false
                break;
            }
        }
        if(!found) {
            cout << "False" << endl;
        }  else {
            cout << "True" << endl;
        }
    }
}