#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    n++;
	    int i=1;
	    int temp=2;
	    int tempn;
	    int ans=0;
	    while(temp<=n){
	        ans+= ((n/temp)*(temp/2));
	        tempn=n%temp;
	        if(tempn/(temp/2)){
	            ans+=(tempn%(temp/2));
	        }
	        temp=temp<<1;
	    }
	    tempn=n%temp;
	    if(tempn/(temp/2)){
	       ans+=(tempn%(temp/2));
	    }
	    cout<<ans<<"\n";
	}
	return 0;
}