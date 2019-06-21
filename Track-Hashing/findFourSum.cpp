#include <bits/stdc++.h>
using namespace std;

void printFourSum(vector<int>& v, int n, int k) {
    // has sum for each pair in a map
    unordered_map<int, pair<int, int>> umap;
    umap.clear();
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            pair<int, int> temp;
            temp.first = i;
            temp.second = j;
            umap[v[i] + v[j]] = temp;
        }
    }

    // we iterate over the array again and for each pair we search for K - pairSum in map, if found and elements distinct
    // we insert in set
    set<vector<int>> s;
    s.clear();
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(v[i] = 60 && v[j] == 68) {
                cout << " Here ";
            }
            int pair_sum = v[i] + v[j];

            if(umap.find(k - pair_sum) != umap.end()) {
                // if sum of 4 elements to k found
                // check if all elements are distinct
                // that is the element found by map should not have value's equal to either i or j
                pair<int, int> p = umap[k - pair_sum];
                if(v[i] == 60 && v[j] == 68) {
                    cout << p.first << " " << p.second;
                }
                if(i != p.first && j != p.first && i != p.second && j != p.second) {
                    vector<int> temp;
                    temp.push_back(v[p.first]);
                    temp.push_back(v[p.second]);
                    temp.push_back(v[i]);
                    temp.push_back(v[j]);
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                }
            }
        }
    }

    if(s.size() == 0) {
        cout << -1 << endl;
        return;
    }

    // for(auto itr = s.begin(); itr != s.end(); itr++) {
    //     for(int i = 0; i < itr -> size(); i++) {
    //         cout << itr->at(i) << " ";
    //     }
    //     cout << "$";
    // }
    cout << endl;
} 

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> v;
        int z;
        for(int i = 0; i < n; i++) {
            cin >> z;
            v.push_back(z);
        }
        //sort(v.begin(), v.end());
        printFourSum(v, n, k);
    }
}