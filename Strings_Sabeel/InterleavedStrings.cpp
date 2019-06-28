#include <bits/stdc++.h>
using namespace std;
bool isInterleave(string A, string B, string C);
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		cout<<isInterleave(a,b,c)<<endl;
	}
	return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete this method */
bool isInterleave(string A, string B, string C)
{
    int m = A.size();
    int n = B.size();

    // dp table of M*N size
    bool dp[m + 1][n + 1];
    memset(dp, false, sizeof(dp));

    // If m+n != c.size(), ans is false
    if(m+n != C.size()) {
        return false;
    }

    // start building dp table
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {

            // base case, if both string a and b are empty
            if(i == 0 && j == 0) {
                dp[i][j] = true;
            }

            // if A is empty and jth char of b matches with jth of c
            else if(i == 0 && B[j - 1] == C[j - 1]) {
                dp[i][j] = dp[i][j - 1];
            }

            // if B is empty and ith char of b matches with ith of c
            else if(j == 0 && A[i - 1] == C[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            }

            // Current char of A matches with current char of C but not with B
            else if(A[i - 1] == C[i + j - 1] && B[j - 1] != C[i + j - 1]) {
                dp[i][j] = dp[i-1][j];
            }

            // Current char of B matches with current char of C but not with A
            else if(A[i - 1] != C[i + j - 1] && B[j - 1] == C[i + j - 1]) {
                dp[i][j] = dp[i][j-1];
            }

            // if curr of c matches with both
            else if(A[i - 1] == C[i + j - 1] && B[j - 1] == C[i + j - 1]) {
                dp[i][j] = (dp[i-1][j] || dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}
