#include<bits/stdc++.h>
using namespace std;
int freq[100];
bool compare(int a, int b){
    if(freq[a]==freq[b]){
        return a<b;
    }else{
        return freq[a]>freq[b];
    }
}
int main(){
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    memset(freq,0,sizeof(freq));
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        freq[a[i]]++;
	    }
	    sort(a,a+n,compare);
	    for(int i=0;i<n;i++){
	        cout<<a[i]<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}