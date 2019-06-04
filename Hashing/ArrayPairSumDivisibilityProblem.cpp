#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    unordered_map<int,int>m;
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int k;
	    cin>>k;
	    if(n&1){
	        cout<<"False\n";
	        continue;
	    }
	    for(int i=0;i<n;i++){
	        a[i]=a[i]%k;
	        m[a[i]]++;
	        //cout<<"A "<<a[i]<<"\n";
	    }
	    bool ans=true;
	    for(int i=0;i<n;i++){
	        if(a[i]==0){
	            continue;
	        }
	        if(m[a[i]]>0){
	            if(m[k-a[i]]>0){
	                m[a[i]]--;
	                m[k-a[i]]--;
	            }else{
	                ans=false;
	                break;
	            }    
	        }
	    }
	    if(m[0]&1){
	        ans=false;
	    }
	    if(ans){
	        cout<<"True\n";
	    }else{
	        cout<<"False\n";
	    }
	}
	return 0;
}