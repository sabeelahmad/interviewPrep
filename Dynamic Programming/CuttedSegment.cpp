#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
ll dp[4001];
ll cutS(ll n, ll x, ll y, ll z){
    if(n==0){
        return 0;
    }
    if(n<0){
        return INT_MIN;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n]=1+max(cutS(n-x,x,y,z),max(cutS(n-y,x,y,z),cutS(n-z,x,y,z)));
}
int main(){
	ll t;
	cin>>t;
	while(t--){
	    ll n;
	    cin>>n;
	    ll x,y,z;
	    cin>>x>>y>>z;
	    memset(dp,-1,sizeof(dp));
	    cout<<cutS(n, x, y, z)<<"\n";
	}
	return 0;
}