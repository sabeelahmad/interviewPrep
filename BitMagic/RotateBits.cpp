#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	    int n,d;
	    cin>>n>>d;
	    d=d%16;
	    int temp;
	    int adj = (1<<16)-1;
	    temp=(n<<d | (n>>(16-d)));
	    cout<<(temp&adj)<<"\n";
	    temp=(n>>d | (n<<(16-d)));
	    cout<<(temp&adj)<<"\n";
	}
	return 0;
}