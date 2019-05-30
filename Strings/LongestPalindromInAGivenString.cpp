#include<bits/stdc++.h>
using namespace std;
int main(){
	//code
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int n=s.size();
	    bool isp[n][n];
	    memset(isp,false,sizeof(isp));
	    for(int i=0;i<n;i++){
	        isp[i][i]=true;
	    }
	    int ans=1;
	    pair<int,int> sans;
	    sans=make_pair(0,1);
	    for(int i=0;i<n-1;i++){
	        if(s[i]==s[i+1]){
	            isp[i][i+1]=true;
	            if(ans==1){
	                ans=2;
	                sans=make_pair(i,i+2);
	            }
	        }
	    }
	    for(int gap=2;gap<n;gap++){
	        for(int i=0;i<n-gap;i++){
	            int j=i+gap;
	            if(isp[i+1][j-1]==true && s[i]==s[j]){
	                isp[i][j]=true;
	                if((j-i+1)>ans){
	                    ans=j-i+1;
	                    sans=make_pair(i,(j+1));
	                }
	            }
	        }
	    }
	    /*
	    for(int i=0;i<n;i++){
	        for(int j=i;j<n;j++){
	            cout<<"I "<<i<<" J "<<j<<" "<<isp[i][j]<<"\n";
	        }
	    }
	    */
	    cout<<s.substr(sans.first,(sans.second-sans.first))<<"\n";
	}
	return 0;
}