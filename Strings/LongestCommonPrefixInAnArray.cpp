#include<bits/stdc++.h>
using namespace std;
int main(){
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    string s[n];
	    for(int i=0;i<n;i++){
	        cin>>s[i];
	    }
	    sort(s,s+n);
	    string ans;
	    for(int i=0;i<s[0].size();i++){
	        int j=1;
	        for(j=1;j<n;j++){
	            if(s[j][i]!=s[0][i]){
	                break;
	            }
	        }
	        if(j==n){
	            ans+=s[0][i];
	        }else{
	            break;
	        }
	    }
	    if(ans.size())
	        cout<<ans<<"\n";
	    else
	        cout<<"-1\n";
	}
	return 0;
}