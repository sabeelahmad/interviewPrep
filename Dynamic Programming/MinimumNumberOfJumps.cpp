#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
//DP solution even though it's O(n^2)
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
	    ll dp[n+1];
	    dp[n-1]=0;
	    for(ll i=n-2;i>=0;i--){
	        ll j=0;
	        ll tempmin=INT_MAX;
	        for(ll j=1;j<=a[i]&&(i+j)<n;j++){
	            tempmin=min(tempmin,dp[i+j]);
	        }
	        dp[i]=tempmin+1;
	    }
	    if(dp[0]>=INT_MAX){
	        dp[0]=-1;
	    }
	    cout<<dp[0]<<"\n";
	}
	return 0;
}