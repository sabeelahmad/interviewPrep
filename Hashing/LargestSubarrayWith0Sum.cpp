include<bits/stdc++.h>
using namespace std;
int maxLen(int A[],int n);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        cout<<maxLen(A,N)<<endl;
    }
}
/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete this function*/
int maxLen(int A[],int n)
{
  //Your code here
  int sum[n+1]={};
  for(int i=1;i<=n;i++){
      sum[i]=sum[i-1]+A[i-1];
  }
  int ans=0;
  map<int,int>m;
  for(int i=0;i<=n;i++){
      if(m.find(sum[i])==m.end()){
          m[sum[i]]=i;
      }else{
          ans=max(ans,i-m[sum[i]]);
      }
  }
  return ans;
}