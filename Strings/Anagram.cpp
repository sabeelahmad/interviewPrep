#include<bits/stdc++.h>
using namespace std;
int main(){
	//code
	int t;
	cin>>t;
	string a,b;
	while(t--){
	    cin>>a>>b;
	    int freqa[26]={};
	    int freqb[26]={};
	    for(auto it:a){
	        freqa[it-'a']++;
	    }
	    for(auto it:b){
	        freqb[it-'a']++;
	    }
	    bool ans=true;
	    for(int i=0;i<26;i++){
	        if(freqa[i]!=freqb[i]){
	            ans=false;
	        }
	    }
	    if(ans){
	        cout<<"YES\n";
	    }else{
	        cout<<"NO\n";
	    }
	}
	return 0;
}