#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
/*
ll editD(ll i, ll j, string a, string b){
    if(i==-1 || j==-1){
        return (i+j+2);
    }
    if(a[i]==b[j]){
        return dp[i][j]=editD(i-1,j-1,a,b);
    }else{
        return dp[i][j]=1+min(editD(i-1,j-1,a,b),min(editD(i,j-1,a,b),editD(i-1,j,a,b)));
    }
}
*/
int main(){
	ll t;
	cin>>t;
	while(t--){
	    ll n,m;
	    cin>>n>>m;
	    string a,b;
	    cin>>a>>b;
	    ll dp[n+1][m+1];
	    for(ll i=0;i<=m;i++){
	        dp[0][i]=i;
	    }
	    for(ll i=0;i<=n;i++){
	        dp[i][0]=i;
	    }
	    for(ll i=1;i<=n;i++){
	        for(ll j=1;j<=m;j++){
	            if(a[i-1]==b[j-1]){
	                dp[i][j]=dp[i-1][j-1];
	            }else{
	                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
	            }
	        }
	    }
	    cout<<dp[n][m]<<"\n";
	}
	return 0;
}