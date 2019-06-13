#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
ll dp[21][21];
ll a[21][21];
ll path(ll i, ll j, ll n){
    //cout<<"I "<<i<<" J "<<j<<"\n";
    //cout<<a[i][j]<<"\n";
    if(i==-1 || j==-1 || j==n){
        return INT_MIN;
    }
    if(i==(n-1)){
        return a[i][j];    
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    return dp[i][j] = max(path(i+1,j,n),max(path(i+1,j-1,n),path(i+1,j+1,n)))+a[i][j];
}
int main(){
	ll t;
	cin>>t;
	while(t--){
	    ll n;
	    cin>>n;
	    memset(a,0,sizeof(a));
	    for(ll i=0;i<n;i++){
	        for(ll j=0;j<n;j++){
	            cin>>a[i][j];
	        }
	    }
	    memset(dp,-1,sizeof(dp));
	    ll ans=-1;
	    for(ll i=0;i<n;i++){
	        ans=max(ans,path(0,i,n));
	    }
	    cout<<ans<<"\n";
	}
	return 0;
}