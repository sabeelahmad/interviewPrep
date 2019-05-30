#include<bits/stdc++.h>
using namespace std;
int strstr(string ,string);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}
/*This is a function problem.You only need to complete the function given below*/

/* The function should return position where the target string 
   matches the string str
Your are required to complete this method */
int strstr(string s, string x){
     //Your code here
     int slen=s.size();
     int xlen=x.size();
     for(int i=0;i<=(slen-xlen);i++){
        if(s.substr(i,xlen)==x){
            return i;
        }
     }
     return -1;
}