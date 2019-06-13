#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
ll dp[101][101][2];
ll maxAmount(ll s, ll e, ll a[], bool turn){
    if(s==e){
        return 0;
    }
    //cout<<"S "<<s<<" E "<<e<<"\n";
    if(dp[s][e][turn]!=-1){
        return dp[s][e][turn];
    }
    if(turn){
        return dp[s][e][turn]=max(maxAmount(s+1,e,a,turn^1)+a[s],maxAmount(s,e-1,a,turn^1)+a[e]);
    }else{
        return dp[s][e][turn]=min(maxAmount(s+1,e,a,turn^1),maxAmount(s,e-1,a,turn^1));
    }
}
int main(){
	ll t;
	cin>>t;
	while(t--){
	    ll n;
	    cin>>n;
	    ll a[n];
	    for(ll i=0;i<n;i++){
	        cin>>a[i];
	    }
	    ll s=0;
	    ll e=n-1;
	    memset(dp,-1,sizeof(dp));
	    cout<<maxAmount(s,e,a,1)<<"\n";
	}
	return 0;
}