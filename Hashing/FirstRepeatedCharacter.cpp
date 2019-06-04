#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int bstring=0;
	    int temp;
	    char ans='1';
	    for(auto it:s){
	        temp = it-'a';
	        if(bstring & (1<<temp)){
	            ans=it;
	            break;
	        }else{
	            bstring = bstring|(1<<temp);
	        }
	    }
	    if(ans=='1'){
	        cout<<"-1\n";
	    }else{
	        cout<<ans<<"\n";    
	    }
	}
	return 0;
}