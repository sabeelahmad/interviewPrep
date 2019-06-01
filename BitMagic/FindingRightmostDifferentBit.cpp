#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	    int a,b;
	    cin>>a>>b;
	    int i=1;
	    while(a && b){
	        //cout<<"A "<<a<<" B "<<b<<"\n";
	        if((a&1) == (b&1)){
	            a=a>>1;
	            b=b>>1;
	            i++;
	        }else{
	            break;
	        }
	    }
	    if(b==0)
	    while(!(a&1) && a){
	        i++;
	        a=a>>1;
	    }
	    if(a==0)
        while(!(b&1) && b){
	        i++;
	        b=b>>1;
	    }	    
	    cout<<i<<"\n";
	}
	return 0;
}