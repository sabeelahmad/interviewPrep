#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	    string a;
	    cin>>a;
	    string b;
	    cin>>b;
	    int freqa[26]={};
	    int freqb[26]={};
	    set<char>s;
	    for(auto it:a){
	        freqa[it-'a']++;
	    }
	    for(auto it:b){
	        if(freqa[it-'a']==0){
	            s.insert(it);
	        }
	        freqb[it-'a']++;
	    }
	    for(auto it:a){
	        if(freqb[it-'a']==0){
	            s.insert(it);
	        }
	    }
	    if(s.size()==0){
	        cout<<"-1\n";    
	    }else{
	        for(auto it:s){
	            cout<<it;
	        }
	        cout<<"\n";
	    }
	}
	return 0;
}