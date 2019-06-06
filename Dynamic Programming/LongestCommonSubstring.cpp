#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    string a,b;
	    cin>>a>>b;
	    int dp[101][101];
	    int ans=0;
	    for(int i=0;i<=n;i++){
	        for(int j=0;j<=m;j++){
	            if(i==0 || j==0){
	                dp[i][j]=0;
	                continue;
	            }
	            
	            if(a[i-1]==b[j-1]){
	                dp[i][j]=dp[i-1][j-1]+1;
	                ans=max(ans,dp[i][j]);    
	            }else{
	                dp[i][j]=0;
	            }
	        }
	    }
	    cout<<ans<<"\n";
	}
	return 0;
}