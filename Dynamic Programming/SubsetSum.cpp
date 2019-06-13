#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
ll dp[101][100001];
bool isPoss(ll i, ll a[], ll sum1, ll sum2){
    if(i==-1){
        if(sum1==sum2){
            return true;
        }else{
            return false;
        }
    }
    if(dp[i][sum1]!=-1){
        return dp[i][sum1];
    }
    return dp[i][sum1]=(isPoss(i-1,a,sum1+a[i],sum2)||isPoss(i-1,a,sum1,sum2+a[i]));
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
	    if(isPoss(n-1,a,0,0)){
	        cout<<"YES\n";
	    }else{
	        cout<<"NO\n";
	    }
	}
	return 0;
}