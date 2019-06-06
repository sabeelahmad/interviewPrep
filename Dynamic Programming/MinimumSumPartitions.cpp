#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
ll dp[2501][2501];
ll minPart(ll i, ll a[], ll s1, ll s2){
    if(i==-1){
        return abs(s1-s2);
    }
    if(dp[s1][s2]!=-1){
        return dp[s1][s2];
    }
    return dp[s1][s2]=min(minPart(i-1,a,s1+a[i],s2),minPart(i-1,a,s1,s2+a[i]));
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
	    memset(dp,-1,sizeof(dp));
	    cout<<minPart(n-1,a,0,0)<<"\n";
	}
	return 0;
}