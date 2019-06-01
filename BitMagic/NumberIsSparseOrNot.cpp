#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int temp=0;
	    bool ans=false;
	    while(n){
	        if(n&1){
	            temp++;
	            if(temp>=2){
	                ans=true;
	                break;
	            }
	        }else{
	            temp=0;
	        }
	        n=n>>1;
	    }
	    if(ans){
	        cout<<"0\n";
	    }else{
	        cout<<"1\n";
	    }
	}
	return 0;
}