#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    int a[n],b[m];
	    unordered_map<int,int> mb;
	    long long suma=0;
	    long long sumb=0;
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        suma+=a[i];
	    }
	    for(int i=0;i<m;i++){
	        cin>>b[i];
	        sumb+=b[i];
	        mb[b[i]]++;
	    }
	    bool ans=false;
	    for(int i=0;i<n;i++){
	        long long temp = (sumb-suma+2*a[i]);
	        if(temp&1){
	            continue;
	        }
	        temp=temp>>1;
	        if(mb[temp]){
	            ans=true;
	            break;
	        }
	    }
	    if(ans){
	        cout<<"1\n";
	    }else{
	        cout<<"-1\n";
	    }
	}
	return 0;
}