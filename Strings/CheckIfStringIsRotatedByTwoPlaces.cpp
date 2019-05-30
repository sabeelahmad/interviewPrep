#include<bits/stdc++.h>
using namespace std;
int main(){
	//code
	int t;
	cin>>t;
	while(t--){
	    string a;
	    cin>>a;
	    string b;
	    cin>>b;
	    int alen=a.size();
	    int blen=b.size();
	    bool ans=true;
	    for(int i=0;i<alen;i++){
	        if(a[i]!=b[(i+2)%blen]){
	            ans=false;
	            break;
	        }
	    }
	    if(ans){
	        cout<<"1\n";
	        continue;
	    }
	    ans=true;
	    for(int i=0;i<alen;i++){
	        if(a[i]!=b[(i-2+blen)%blen]){
	            ans=false;
	            break;
	        }
	    }
	    if(ans){
	        cout<<"1\n";
	        continue;
	    }
	    cout<<"0\n";
	}
	return 0;
}