#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
int main(){
	ll t;
	cin>>t;
	while(t--){
	    ll n,m;
	    cin>>n>>m;
	    string a,b;
	    cin>>a>>b;
	    ll dp[101][101];
	    memset(dp,0,sizeof(dp));
	    for(ll i=0;i<=n;i++){
	        dp[i][0]=0;
	    }
	    for(ll i=0;i<=m;i++){
	        dp[0][i]=0;
	    }
	    for(ll i=1;i<=n;i++){
	        for(ll j=1;j<=m;j++){
	            if(a[i-1]==b[j-1]){
	                dp[i][j]=1+dp[i-1][j-1];
	            }else{
	                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	            }
	        }
	    }
	    cout<<dp[n][m]<<"\n";
	}
	return 0;
}