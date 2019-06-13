#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	    long long n;
	    cin>>n;
	    long long a[n];
	    long long sum[n+1]={};
	    unordered_map<long long, long long>m;
	    long long ans=0;
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        sum[i+1]=sum[i]+a[i];
	        m[sum[i+1]]++;
	    }
	    m[0]++;
	    long long temp;
	    for(auto it:m){
	        //cout<<"f "<<it.first<<" s "<<it.second<<"\n";
	        temp=it.second;
	        ans+=(temp*(temp-1))/2;
	    }
	    cout<<ans<<"\n";
	}
	return 0;
}