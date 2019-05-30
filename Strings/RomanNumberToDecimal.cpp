#include<bits/stdc++.h>
using namespace std;
int main(){
	//code
	int t;
	cin>>t;
	map<char,int> m;
	m.insert(make_pair('I', 1));
	m.insert(make_pair('V', 5));
	m.insert(make_pair('X', 10));
	m.insert(make_pair('L', 50));
	m.insert(make_pair('C', 100));
	m.insert(make_pair('D', 500));
	m.insert(make_pair('M', 1000));
	while(t--){
	    string s;
	    cin>>s;
	    int ans=0;
	    for(int i=0;i<s.size()-1;i++){
	        if(m[s[i]]<m[s[i+1]]){
	            ans-=m[s[i]];
	        }else{
	            ans+=m[s[i]];
	        }
	    }
	    ans+=m[s[s.size()-1]];
	    cout<<ans<<"\n";
	}
	return 0;
}