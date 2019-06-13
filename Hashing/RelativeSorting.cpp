#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    int a[n], b[m];
	    int freq[1000001]={};
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        freq[a[i]]++;
	    }
	    vector<int> ans;
	    for(int i=0;i<m;i++){
	        cin>>b[i];
	        if(freq[b[i]]>0){
	            while(freq[b[i]]--){
	                ans.push_back(b[i]);
	            }
	        }
	    }
	    sort(a,a+n);
	    for(int i=0;i<n;i++){
	        if(freq[a[i]]>0){
	            while(freq[a[i]]--){
	                ans.push_back(a[i]);
	            }
	        }
	    }
	    for(auto it:ans){
	        cout<<it<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}