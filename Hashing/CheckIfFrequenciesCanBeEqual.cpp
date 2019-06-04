#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	    string st;
	    cin>>st;
	    int freq[26]={};
	    for(auto it:st){
	        freq[it-'a']++;
	    }
	    map<int,int> m;
	    for(int i=0;i<26;i++){
	        if(freq[i]>0)
	        m[freq[i]]++;
	    }
	    if(m.size()>2){
	        cout<<"0\n";
	        continue;
	    }
	    if(m.size()==1){
	        cout<<"1\n";
	        continue;
	    }
	    auto it=m.begin();
	    pair<int,int> temp = make_pair(it->first,it->second);
	    it++;
	    if(temp.first==1 && temp.second==1){
	        cout<<"1\n";
	        continue;
	    }
	    if(it->second>1){
	        cout<<"0\n";
	        continue;
	    }
	    if((it->first - temp.first)==1){
	        cout<<"1\n";
	        continue;
	    }
	    cout<<"0\n";
	}
	return 0;
}