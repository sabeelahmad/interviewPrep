#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	    long long n;
	    cin>>n;
	    if(n==0){
	        cout<<"NO\n";
	        continue;
	    }
	    long long i=0;
	    bool ans=false;
	    while(i<40){
	        long long temp=(1<<i);
	        if((n&temp)==n){
	            ans=true;
	            break;
	        }
	        i++;
	    }
	    if(ans){
	        cout<<"YES\n";
	    }else{
	        cout<<"NO\n";
	    }
	}
	return 0;
}