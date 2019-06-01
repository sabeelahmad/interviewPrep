#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	    int a,b;
	    cin>>a>>b;
	    int temp=a^b;
	    int ans=0;
	    while(temp){
	        ans+=(temp&1);
	        temp=temp>>1;
	    }
	    cout<<ans<<"\n";
	}
	return 0;
}