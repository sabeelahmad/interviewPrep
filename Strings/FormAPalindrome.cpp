#include<bits/stdc++.h>
using namespace std;
int minchange(string s, int i, int j, int dp[50][50]){
    if(i==j){
        return dp[i][j]=0;
    }else if(i>j){
        return dp[i][j]=INT_MAX;
    }else if(i==j-1){
        return dp[i][j]=(!(s[i]==s[j]));
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s[i]==s[j]){
        return dp[i][j]=minchange(s,i+1,j-1,dp);
    }else{
        return dp[i][j]=min(minchange(s,i+1,j,dp), minchange(s,i,j-1,dp))+1;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int n=s.size();
	    int dp[50][50];
	    memset(dp,-1,sizeof(dp));
	    cout<<min(n-1,minchange(s,0,n-1,dp))<<"\n";
	}
	return 0;
}