#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    int a[n],b[m];
	    unordered_set<int>s;
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        s.insert(a[i]);
	    }
	    bool ans=true;
	    for(int i=0;i<m;i++){
	        cin>>b[i];
	        if(s.find(b[i])==s.end()){
	            ans=false;
	        }
	    }
	    if(ans){
	        cout<<"Yes\n";
	    }else{
	        cout<<"No\n";
	    }
	}
	return 0;
}