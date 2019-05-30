#include <bits/stdc++.h>
using namespace std;
int atoi(string str);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		cout<<atoi(s)<<endl;
	}
}
int atoi(string str)
{
    //Your code here
    int p=0;
    int ret=0;
    int minus=1;
    if(str[0]=='-'){
        minus=-1;
    }
    reverse(str.begin(), str.end());
    for(auto it:str){
        if(it=='-'){
            continue;
        }
        if((it-'0')>=0 && (it-'0')<=9){
            ret+=((it-'0')*pow(10,p++));
        }else{
            return -1;
        }
    }
    return minus*ret;
}