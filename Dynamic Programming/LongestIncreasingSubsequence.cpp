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
	    ll a[n];
	    for(ll i=0;i<n;i++){
	        cin>>a[i];
	    }
	    ll dp[n];
	    dp[0]=1;
	    for(ll i=1;i<n;i++){
	        dp[i]=1;
	        for(ll j=i-1;j>=0;j--){
	            if(a[j]<a[i]){
	                dp[i]=max(dp[j]+1,dp[i]);
	            }
	        }
	    }
	    ll mx=-1;
	    for(ll i=0;i<n;i++){
	        mx=max(mx,dp[i]);
	    }
	    cout<<mx<<"\n";
	}
	return 0;
}