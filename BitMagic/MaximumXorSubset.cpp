#include<bits/stdc++.h>
using namespace std;
int dp[1024][31];
long ans(int i, int n, int xr, int a[], int dp[1023][31]){
    if(i==n){
        return xr;
    }
    if(dp[xr][i]!=-1){
        return dp[xr][i];
    }else{
        return dp[xr][i]=max(ans(i+1,n,xr,a,dp), ans(i+1,n,xr^a[i],a,dp));
    }
}
int main(){
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    memset(dp,-1,sizeof(dp));
	    cout<<ans(0,n,0,a,dp)<<"\n";
	}
	return 0;
}