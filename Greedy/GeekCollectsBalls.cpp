#include<bits/stdc++.h>
typedef int ll;
typedef long double ld;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--){
	    ll n,m;
	    cin>>n>>m;
	    ll a[n];
	    ll b[m];
	    ll suma[n+1]={};
	    map<ll,ll>ma;
	    ll sumb[m+1]={};
	    vector<pair<ll,ll>>in;
	    for(ll i=0;i<n;i++){
	        cin>>a[i];
	        suma[i+1]=suma[i]+a[i];
	        ma[a[i]]=(i+1);
	    }
	    for(ll i=0;i<m;i++){
	        cin>>b[i];
	        sumb[i+1]=sumb[i]+b[i];
	        if(ma.find(b[i])!=ma.end()){
	            in.push_back(make_pair(ma[b[i]],i+1));
	        }
	    }
	    /*
	    for(ll i=0;i<=n;i++){
	        cout<<suma[i]<<"\n";
	    }
	    cout<<"\n";
	    for(ll i=0;i<=m;i++){
	        cout<<sumb[i]<<"\n";
	    }
	    cout<<"\n";
	    */
	    if(in.size()==0){
	        cout<<max(suma[n],sumb[m])<<"\n";
	        continue;
	    }
	    ll ans=max(suma[in[0].first],sumb[in[0].second]);
	    ll len=in.size();
	    for(ll i=1;i<len;i++){
	        //cout<<"ANS  "<<ans<<"\n";
	        ans+=max(suma[in[i].first]-suma[in[i-1].first], sumb[in[i].second]-sumb[in[i-1].second]);
	    }
	    ans+=max(suma[n]-suma[in[len-1].first],sumb[m]-sumb[in[len-1].second]);
	    cout<<ans<<"\n";
	}
	return 0;
}
