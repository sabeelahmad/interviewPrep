#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    string p;
	    cin>>p;
	    int minind[26];
	    for(int i=0;i<26;i++){
	        minind[i]=INT_MAX;
	    }
	    int i=0;
	    for(auto it:s){
	        minind[it-'a']=min(minind[it-'a'],i++);
	    }
	    int minInd=INT_MAX;
	    char ans='$';
	    for(auto it:p){
	        if(minInd>minind[it-'a']){
	            minInd=minind[it-'a'];
	            ans=it;
	        }
	    }
	    cout<<ans<<"\n";
	}
	return 0;
}