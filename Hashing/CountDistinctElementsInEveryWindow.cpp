#include <bits/stdc++.h>
using namespace std;
void countDistinct(int [], int , int );
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		
		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		countDistinct(a,k,n);cout<<endl;
	}
	return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete below method */
void countDistinct(int A[], int k, int n){
    //Your code here
    unordered_map<int,int>m;
    for(int i=0;i<k;i++){
        m[A[i]]++;
    }
    cout<<m.size()<<" ";
    for(int i=k;i<n;i++){
        m[A[i-k]]--;
        if(!m[A[i-k]]){
            m.erase(A[i-k]);
        }
        m[A[i]]++;
        cout<<m.size()<<" ";
    }
}