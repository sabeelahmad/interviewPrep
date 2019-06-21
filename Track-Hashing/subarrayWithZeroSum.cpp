#include <bits/stdc++.h>
using namespace std;

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
        
        // to get largest subarray with sum 0
        // we get has sum till each index in a map
        // if at any index sum is same as a prev index, means elements between those two indices
        // add up to 0, hence we have a subarray with sum 0
        map<int, int> m;
        m.clear();
        
        int sum = 0, maxLen = 0;
        for(int i = 0; i < n; i++) {
            sum += vec[i];
            
            // if num is 0 and maxLen is 0, make it 1 
            if(vec[i] == 0 && maxLen == 0) {
                maxLen = 1;
            }
            // if sum = 0, maxLen = i+1, as sum from 0 to i is 0
            if(sum == 0) {
                maxLen = i + 1;
            }
            
            // see if this sum is in Hash table
            if(m.find(sum) != m.end()) {
                // update maxLen if previous sum is at a distance greater than current maxLen
                maxLen = max(maxLen, i - m[sum]);
            } else {
                // put this sum in map only if it hasnt been seen before
                // we want earliest entry of sum in map, not latest
                m[sum] = i;
            }
        }
        cout << maxLen << endl;
    }
}