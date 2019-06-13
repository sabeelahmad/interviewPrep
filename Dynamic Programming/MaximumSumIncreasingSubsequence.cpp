#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
ll dp[1000001];
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
	    dp[0]=a[0];
	    for(ll i=1;i<n;i++){
	        dp[i]=0;
	        for(ll j=i-1;j>=0;j--){
	            if(a[i]>a[j])
	            dp[i]=max(dp[i],dp[j]);
	        }
	        dp[i]+=a[i];
	    }
	    ll mx=-1;
	    for(ll i=0;i<n;i++){
	        mx=max(dp[i],mx);
	    }
	    cout<<mx<<"\n";
	}
	return 0;
}