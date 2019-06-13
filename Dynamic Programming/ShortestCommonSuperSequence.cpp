#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
ll dp[101][101];
/*
ll shortestSuperS(ll i, ll j, string a, string b){
    if(i==-1 || j==-1){
        return (i+j);
    }
    if(a[i]==b[j]){
        return dp[i][j]=1+shortestSuperS(i-1,j-1,a,b);
    }else{
        return dp[i][j]=1+min(shortestSuperS(i-1,j,a,b),shortestSuperS(i,j-1,a,b));
    }
}
*/
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--){
	    string a,b;
	    cin>>a>>b;
	    ll n=a.size();
	    ll m=b.size();
	    memset(dp,-1,sizeof(dp));
	    for(ll i=0;i<=n;i++){
	        dp[i][0]=i+0;
	    }
	    for(ll i=0;i<=m;i++){
	        dp[0][i]=i+0;
	    }
	    for(ll i=1;i<=n;i++){
	        for(ll j=1;j<=m;j++){
	            if(a[i-1]==b[j-1]){
	                dp[i][j]=1+dp[i-1][j-1];
	            }else{
	                dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
	            }
	        }
	    }
	    cout<<dp[n][m]<<"\n";
	}
	return 0;
}