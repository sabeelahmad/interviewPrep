#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        // we need to find the first repeating character
        // simply create map of frequencies of a character
        // if frequency for a character becomes 2, we print it
        unordered_map<char, int> umap;
        umap.clear();
        bool ans = false;
        int n  = s.length();
        for(int i = 0; i < n; i++) {
            umap[s[i]]++;
            if(umap[s[i]] == 2) {
                cout << s[i] << endl;
                ans = true;
                break;
            }
        }
        if(!ans) {
            cout << -1 << endl;
        }
    }
}