#include<bits/stdc++.h>
using namespace std;
vector<string> ans;
void print(string o, string s){
    if(s.size()==0){
        ans.push_back(o);
    }
    for(int i=0;i<s.size();i++){
        print(s[i]+o, s.substr(0,i)+s.substr(i+1));
    }
}
int main(){
	//code
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    string o="";
	    print(o,s);
	    sort(ans.begin(),ans.end());
	    for(auto it:ans){
	        cout<<it<<" ";
	    }
	    cout<<"\n";
	    ans.clear();
	}
	return 0;
}