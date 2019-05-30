#include<bits/stdc++.h>
using namespace std;
int main(){
	//code
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
	    string s;
	    getline(cin,s);
	    //cout<<s<<"\n";
	    int chk=0;
	    int len=0;
	    int i=0;
	    for(auto it:s){
	        if(!(chk&(1<<(it-97)))){
	            cout<<it;
	            chk=(chk|(1<<(it-97)));
	        }
	    }
	    cout<<"\n";
	}
	return 0;
}