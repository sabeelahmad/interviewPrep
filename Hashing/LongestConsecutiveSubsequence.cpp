#include <bits/stdc++.h>
using namespace std;
int findLongestConseqSubseq(int arr[], int n);
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  cout<<findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
/*This is a function problem.You only need to complete the function given below*/

int findLongestConseqSubseq(int arr[], int n){
  //Your code here
  int maxlen=1;
  int templen=1;
  sort(arr,arr+n);
  for(int i=0;i<n-1;i++){
      while((arr[i]+1)==arr[i+1] && (i<(n-1))){
          templen++;
          i++;
      }
      maxlen=max(templen,maxlen);
      templen=1;
  }
  return maxlen;
}