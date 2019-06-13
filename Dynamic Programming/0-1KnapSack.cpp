#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int knpsk(int i, int n, int vl[], int wt[], int W){
    if(W<0){
        return INT_MIN;
    }
    if(W==0){
        return 0;
    }
    if(i==n){
        return 0;
    }
    if(dp[i][W]!=-1){
        return dp[i][W];
    }
    return dp[i][W]=max(knpsk(i+1,n,vl,wt,W-wt[i])+vl[i], knpsk(i+1,n,vl,wt,W));
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	    int n,W;
	    cin>>n>>W;
	    int vl[n],wt[n];
	    for(int i=0;i<n;i++){
	        cin>>vl[i];
	    }
	    for(int i=0;i<n;i++){
	        cin>>wt[i];
	    }
	    memset(dp,-1,sizeof(dp));
	    for(int i=0;i<n;i++){
	        dp[i][0]=0;
	    }
	    for(int i=0;i<W;i++){
	        dp[n][i]=0;
	    }
	    for(int i=n-1;i>=0;i--){
	        for(int j=1;j<=W;j++){
	            if(j>=wt[i])
	                dp[i][j]=max(dp[i+1][j-wt[i]]+vl[i],dp[i+1][j]);
	            else
	                dp[i][j]=dp[i+1][j];
	        }
	    }
	    int ans=-1;
	    for(int i=0;i<=W;i++){
	        ans=max(ans,dp[0][i]);
	    }
	    cout<<ans<<"\n";
	}
	return 0;
}