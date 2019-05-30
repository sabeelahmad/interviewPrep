#include<bits/stdc++.h>
using namespace std;
int main(){
	//code
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int last[257]={};
	    memset(last,-1,sizeof(last));
	    last[s[0]]=0;
	    int pre;
	    int maxlen=1;
	    int curlen=1;
	    for(int i=1;i<s.size();i++){
	        pre=last[s[i]];
	        last[s[i]]=i;
	        if(pre==-1 || (i-curlen)>pre){
	            curlen++;
	        }else{
	            maxlen=max(maxlen,curlen);
	            curlen=i-pre;
	        }
	    }
	    maxlen=max(maxlen,curlen);
	    cout<<maxlen<<"\n";
	}
	return 0;
}