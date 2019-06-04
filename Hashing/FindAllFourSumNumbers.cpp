#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	    set<pair<pair<int,int>,pair<int,int>>>ans;
	    int n, K;
	    cin>>n>>K;
	    int a[n];
	    unordered_map<int,int>m;
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        m[a[i]]++;
	    }
	    int temp[4];
	    unordered_map<int,int> tempm;
	    for(int i=0;i<n;i++){
	        for(int j=i+1;j<n;j++){
	            for(int k=j+1;k<n;k++){
	                tempm.clear();
	                if(m.find(K-a[i]-a[j]-a[k])!=m.end()){
	                    temp[0]=a[i];
	                    temp[1]=a[j];
	                    temp[2]=a[k];
	                    temp[3]=K-a[i]-a[j]-a[k];
	                    sort(temp,temp+4);
	                    bool chk=false;
	                    for(int z=0;z<4;z++){
	                        tempm[temp[z]]++;
	                        if(tempm[temp[z]]>m[temp[z]]){
	                           chk=true;
	                           break;
	                        }
	                    }
	                    if(chk){
	                        continue;
	                    }
	                    ans.insert(make_pair(make_pair(temp[0],temp[1]),make_pair(temp[2],temp[3])));
	                }
	            }
	        }
	    }
	    if(ans.size()==0){
	        cout<<"-1\n";
	        continue;
	    }
	    for(auto it:ans){
	        cout<<it.first.first<<" "<<it.first.second<<" "<<it.second.first<<" "<<it.second.second<<" $";
	    }
	    cout<<"\n";
	}
	return 0;
}