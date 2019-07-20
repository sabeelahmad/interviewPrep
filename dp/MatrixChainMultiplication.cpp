#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define MAX 101

// We try placing a bracket at each position and then recursively do the rest and get min
int matrixOperations(int a[], int i, int j, int dp[MAX][MAX]) {
    // base case, only one matrix
    if(i == j) {
        return 0;
    }
    // check if state calculated
    if(dp[i][j] > -1) {
        return dp[i][j];
    }
    int minimum = INT_MAX;
    // try breaking at each K and recursively get cost of two halves
    for(int k = i; k < j; k++) {
        // One half will be from i to k
        // other from k + 1 to j
        // plus add the cost of this breakage,
        int count = matrixOperations(a, i, k, dp) + matrixOperations(a, k + 1, j, dp) + (a[i - 1]*a[k]*a[j]);
        minimum = min(minimum, count);
    }
    dp[i][j] = minimum;
    return dp[i][j];
}

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
	    int dp[MAX][MAX];
	    memset(dp, -1, sizeof(dp));
	    cout << matrixOperations(a, 1, n - 1, dp) << endl;
	}
	return 0;
}
