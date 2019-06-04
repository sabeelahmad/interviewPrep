#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int temp;
	    multiset<int>a;
	    multiset<int>b;
	    for(int i=0;i<n;i++){
	        cin>>temp;
	        a.insert(temp);
	    }
	    for(int i=0;i<n;i++){
	        cin>>temp;
	        b.insert(temp);
	    }
	    if(a==b){
	        cout<<"1\n";
	    }else{
	        cout<<"0\n";
	    }
	}
	return 0;
}