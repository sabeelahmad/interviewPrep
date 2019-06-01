#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int mx=-1;
	    int temp=0;
	    while(n){
	        if(n&1){
	            temp++;
	            mx=max(mx,temp);
	        }else{
	            temp=0;
	        }
	        n=n>>1;
	    }
	    cout<<mx<<"\n";
	}
	return 0;
}