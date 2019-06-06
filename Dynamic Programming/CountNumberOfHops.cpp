#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
int main(){
	ll t;
	cin>>t;
	while(t--){
	    ll n;
	    cin>>n;
	    ll ans=-1;
	    if(n==1){
	        ans=1;
	    }
	    if(n==2){
	        ans=2;
	    }
	    if(n==3){
	        ans=4;
	    }
	    ll dp[n]={};
	    dp[n-1]=1;
	    dp[n-2]=2;
	    dp[n-3]=4;
	    for(ll i=n-4;i>=0;i--){
	        dp[i]=dp[i+1]+dp[i+2]+dp[i+3];
	    }
	    if(ans==-1){
	        cout<<dp[0]<<"\n";
	    }else{
	        cout<<ans<<"\n";
	    }
	}
	return 0;
}