#include<bits/stdc++.h>
using namespace std;
int main(){
	//code
	int t;
	cin>>t;
	while(t--){
	    //cout<<"HELLO\n";
	    vector<string> a;
	    string s;
	    cin>>s;
	    char c;
	    string temp;
	    for(auto it:s){
	        if(it=='.'){
	            a.push_back(temp);
	            temp="";
	        }else{
	            temp+=it;
	        }
	    }
	    a.push_back(temp);
	    reverse(a.begin(),a.end());
	    cout<<a[0];
	    for(int i=1;i<a.size();i++){
	        cout<<"."<<a[i];
	    }
	    cout<<"\n";
	}
	return 0;
}