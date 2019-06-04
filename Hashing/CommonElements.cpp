#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	    int n1,n2,n3;
	    cin>>n1>>n2>>n3;
	    int a[n1], b[n2], c[n3];
	    unordered_set<int> sa,sb;
	    for(int i=0;i<n1;i++){
	        cin>>a[i];
	        sa.insert(a[i]);
	    }
	    for(int i=0;i<n2;i++){
	        cin>>b[i];
	        if(sa.find(b[i])!=sa.end()){
	            sb.insert(b[i]);
	        }
	    }
	    set<int>ans;
	    for(int i=0;i<n3;i++){
	        cin>>c[i];
	        if(sb.find(c[i])!=sb.end()){
	            ans.insert(c[i]);
	        }
	    }
	    if(ans.size()==0){
	        cout<<"-1\n";
	        continue;
	    }
	    for(auto it:ans){
	        cout<<it<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}