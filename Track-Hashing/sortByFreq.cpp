#include <bits/stdc++.h>
using namespace std;

// map to store freqs
unordered_map<int, int> umap1;
//unordered_map<int, int> umap2;

bool sortByFreq(int a, int b) {
    if(umap1[a] == umap1[b]) {
        return a < b;
    }
    return (umap1[a] > umap1[b]);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> vec;
        int z;
        for(int i = 0; i < n; i++) {
            cin >> z;
            vec.push_back(z);
        }

        umap1.clear();
        //umap2.clear();
        for(int i = 0; i < n; i++) {
            umap1[vec[i]]++;
            // if(umap2[vec[i]] == 0) {
            //     umap2[vec[i]] = i;
            // }
        }
        sort(vec.begin(), vec.end(), sortByFreq);
        for(int i = 0; i < n; i++) {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
}