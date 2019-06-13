#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	    int n,m,x;
	    cin>>n>>m>>x;
	    int a[n],b[m];
	    unordered_map<int,int>ma;
	    unordered_map<int,int>mb;
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        ma[a[i]]++;
	    }
	    for(int i=0;i<m;i++){
	        cin>>b[i];
	        mb[b[i]]++;
	    }
	    vector<pair<int,int>>ans;
	    for(int i=0;i<n;i++){
	        if(mb[x-a[i]]){
	            ans.push_back(make_pair(a[i],x-a[i]));
	        }
	    }
	    if(ans.size()==0){
	        cout<<"-1\n";
	        continue;
	    }
	    sort(ans.begin(),ans.end());
	    for(int i=0;i<ans.size()-1;i++){
	        cout<<ans[i].first<<" "<<ans[i].second<<", ";
	    }
	    cout<<ans[ans.size()-1].first<<" "<<ans[ans.size()-1].second<<"\n";
	}
	return 0;
}