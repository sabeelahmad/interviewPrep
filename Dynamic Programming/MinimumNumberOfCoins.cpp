#include<bits/stdc++.h>
using namespace std;
long dp[1000001];
//Used Greedy, commented out the DP solution for reference
vector<int>ans;
/*
long minChange(int coins[], int i, int n, int N){
    //cout<<"N "<<N<<"\n";
    if(N<0){
        return INT_MAX;
    }
    if(N==0){
        return 0;
    }
    if(i==n){
        return INT_MAX;
    }
    if(dp[N]!=-1){
        return dp[N];
    }
    long temp1=minChange(coins,i+1,n,N);
    long temp2=minChange(coins,i,n,N-coins[i])+1;
    if(temp2<temp1){
        ans.push_back(coins[i]);
        return dp[N]=temp2;
    }else{
        return dp[N]=temp1;
    }
}
*/
int main(){
	int t;
	cin>>t;
	int coins[]={1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
	while(t--){
	    int n;
	    cin>>n;
	    for(int i=9;i>=0;i--){
	        while(n>=coins[i]){
	            n-=coins[i];
	            ans.push_back(coins[i]);
	        }
	    }
	    for(auto it:ans){
	        cout<<it<<" ";
	    }
	    ans.clear();
	    cout<<"\n";
	}
	return 0;
}