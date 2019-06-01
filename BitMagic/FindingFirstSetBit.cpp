#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    if(n==0){
	        cout<<0<<"\n";
	        continue;
	    }
	    int i=1;
	    while(n){
	        if(n&1){
	            break;
	        }else{
	            n=n>>1;
	        }
	        i++;
	    }
	    cout<<i<<"\n";
	}
	return 0;
}