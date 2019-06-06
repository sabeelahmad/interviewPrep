#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
ll dp[301][301];
ll coinChange(ll a[], ll i, ll N){
    if(N==0){
        return 1;
    }
    if(i==-1){
        return 0;
    }
    if(N<0){
        return 0;
    }
    if(dp[i][N]!=-1){
        return dp[i][N];
    }
    return dp[i][N] = (coinChange(a,i-1,N)+coinChange(a,i,N-a[i]));
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
	    int N;
	    cin>>N;
	    memset(dp,-1,sizeof(dp));
	    cout<<coinChange(a,n-1,N)<<"\n";
	}
	return 0;
}