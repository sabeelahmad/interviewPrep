#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    int a[n];
	    unordered_map<int,int>m;
	    int ans=-1;
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        m[a[i]]++;
	    }
	    for(int i=0;i<n;i++){
	        if(m[a[i]]==k){
	            ans=a[i];
	            break;
	        }
	    }
	    cout<<ans<<"\n";
	}
	return 0;
}