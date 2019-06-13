#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
ll dp[11][51];
ll eggDrop(ll n, ll k){
    if(k==0 || k==1){
        return k;
    }
    if(n==1){
        return k;
    }
    
    if(dp[n][k]!=-1){
        return dp[n][k];
    }
    ll mn=INT_MAX;
    for(ll i=1;i<=k;i++){
        mn=min(mn,max(eggDrop(n-1,i-1),eggDrop(n,k-i)));
    }
    return dp[n][k]=mn+1;
}
int main(){
	ll t;
	cin>>t;
	while(t--){
	    ll n,k;
	    cin>>n>>k;
	    memset(dp,-1,sizeof(dp));
	    cout<<eggDrop(n,k)<<"\n";
	}
	return 0;
}