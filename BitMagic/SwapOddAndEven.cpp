#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int even = n&0xAAAA;
	    int odd = n&0x5555;
	    even=even>>1;
	    odd=odd<<1;
	    cout<<(even|odd)<<"\n";
	}
	return 0;
}