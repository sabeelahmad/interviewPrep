#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

// we simply calculate force at points between two values using binary search rather than considering all pts
// if force at mid is less than reqd precision we have our pt, else if it is +ve, we shift the start to mid, since forces are dominant on lhs and
// we want to reduce their effect, if it is -ve wo do the opposite

ld force(ld p, ld a[], ll n){
    ld ret=0;
    for(ll i=0;i<n;i++){
        ret+=(1/(p-a[i]));
    }
    return ret;
}

ld zero(ld st, ld end, ld a[], ll n){
    ld mid;
    while(st<end){
        mid=(st+end)/2;
        //cout<<"MID "<<mid<<"\n";
        ld temp=force(mid,a,n);
        if(abs(temp)<0.0000000000001){
            return mid;
        }else if(temp>0){
            st=mid;
        }else{
            end=mid;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--){
        ll n;
        cin>>n;
        ld a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<std::setprecision(2);
        cout<<std::fixed;
        for(ll i=1;i<n;i++){
            cout<<zero(a[i-1],a[i],a,n)<<" ";
        }
        cout<<"\n";
	}
	return 0;
}
