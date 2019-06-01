#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    int temp=0;
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        temp=temp^a[i];
	    }
	    cout<<temp<<"\n";
	}
	return 0;
}