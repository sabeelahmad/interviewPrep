#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    if((n&(1<<k))){
	        cout<<"Yes\n";
	    }else{
	        cout<<"No\n";
	    }
	}
	return 0;
}