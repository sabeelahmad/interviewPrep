#include<bits/stdc++.h>
using namespace std;

void helper(int* arr, int n, vector<int> &xors, vector<int>& subsets) {
    if(n == 0) {
        int subsetXOR = 0;
        for(int i = 0; i < subsets.size(); i++) {
            subsetXOR = subsets[i] ^ subsetXOR;
        }
        xors.push_back(subsetXOR);
        return;
    }

    // consider no
    subsets.push_back(arr[0]);
    helper(arr + 1, n - 1, xors, subsets);
    subsets.pop_back();
    // exclude
    helper(arr + 1, n - 1, xors, subsets);
}

int maxXORsubset(int * arr, int n, vector<int> &xors) {
    vector<int> currentSubset;
    helper(arr, n, xors, currentSubset);
    int best = INT_MIN;
    for(int i = 0; i < xors.size(); i++) {
        if(xors[i] > best) {
            best = xors[i];
        }
    }
    return best;
}

int main()
 {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    int * arr = new int[n];
	    for(int i = 0; i < n; i++) {
	        cin >> arr[i];
	    }
	    vector<int> xors;
	    cout << maxXORsubset(arr, n, xors) << endl;
	}
	return 0;
}
