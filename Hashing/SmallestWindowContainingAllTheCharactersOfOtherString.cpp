#include<bits/stdc++.h>
using namespace std;
bool chk(int t[], int s[]){
    for(int i=0;i<26;i++){
        if(t[i]>s[i]){
            return false;
        }
    }
    return true;
}
int main(){
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    string t;
	    cin>>t;
	    int freqt[26]={};
	    for(auto it:t){
	        freqt[it-'a']++;
	    }
	    int i=0,j=0;
	    int mxlen=INT_MAX;
	    pair<int,int> ans;
	    int n=s.size();
	    int freqs[26]={};
	    for(int i=0;i<n;i++){
	        while(!chk(freqt,freqs) && i<n){
	            freqs[s[i]-'a']++;
	            //cout<<"S[i] "<<s[i]<<" FREQ "<<freqs[s[i]]<<"\n";
	            //cout<<"HELLO \n";
	            i++;
	        }
	        i--;
	        while(chk(freqt,freqs)){
	            freqs[s[j]-'a']--;
	            j++;
	            //cout<<"J "<<j<<"\n";
	            if(mxlen>(i-j+2)){
	                mxlen=(i-j+2);
	                ans=make_pair(j,i);
	            }
	        }
	    }
	    if(mxlen==INT_MAX){
	        cout<<"-1\n";
	    }else{
	        cout<<s.substr(ans.first-1,ans.second-ans.first+2)<<"\n";
	    }
	}
	return 0;
}