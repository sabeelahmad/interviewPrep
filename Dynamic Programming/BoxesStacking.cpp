#include<bits/stdc++.h>
using namespace std;
int maxHeight(int height[],int width[],int length[],int n);
int main()
{
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	
 	int A[1000],B[1000],C[10001];
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		A[i]=a;
		B[i]=b;
		C[i]=c;
	}
	cout<<maxHeight(A,B,C,n)<<endl;
    }
}
/*This is a function problem.You only need to complete the function given below*/
/*The function takes an array of heights, width and 
length as its 3 arguments where each index i value 
determines the height, width, length of the ith box. 
Here n is the total no of boxes.*/
struct st
{
    int l,w,h;
};
bool compare(st s1,st s2)
{
    return(s1.l*s1.w>s2.l*s2.w);
}

int dp[301][102][102];
int func(st s[],int n,int i,int j)
{
    if(n==0)
        return 0;
    
    if(dp[n][i][j]!=-1)
        return dp[n][i][j];
        
    
    int ans1=0,ans2=0,ans3=0,ans4=0; 
    int p,q,temp;

    p=s[0].l;
    q=s[0].w;
    if(p<q)
        swap(p,q);
     
    if(p<i&&q<j)
    {
        ans1=s[0].h+func(s+1,n-1,p,q);
    }
    
    ans2=func(s+1,n-1,i,j);
    dp[n][i][j]=max(ans1,ans2);
    return dp[n][i][j];
    
}
int maxHeight(int height[],int width[],int length[],int n)
{
    //Your code here
    //int dp[n+1][10002];
    memset(dp,-1,sizeof(dp));
    st s[3*n];
    int k=0;
    for(int i=0;i<n;i++)
    {
        s[k].l=length[i];
        s[k].w=width[i];
        s[k].h=height[i];
        k++;
        
        s[k].l=length[i];
        s[k].w=height[i];
        s[k].h=width[i];
        k++;
        
        s[k].l=width[i];
        s[k].w=height[i];
        s[k].h=length[i];
        k++;
    }
    sort(s,s+k,compare);
    //for(int i=0;i<k;i++)
      //  cout<<s[i].l<<" "<<s[i].w<<" "<<s[i].h<<endl;
    return func(s,k,101,101);
}