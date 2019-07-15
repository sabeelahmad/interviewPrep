#include<bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N, E;
        cin>>N>>E;

        vector<int> g[N];
        bool vis[N];

        memset(vis, false, sizeof(vis));

        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0,g,vis);

        cout<<endl;
    }
}
}
/*This is a function problem.You only need to complete the function given below*/
/* Function to do DFS of graph
*  g[]: array of vectors to represent graph
*  vis[]: array to keep track of visited vertex
*/
void dfs(int s, vector<int> g[], bool vis[])
{
    // mark current node visited
    vis[s] = true;
    // print it
    cout << s << " ";
    // now call recursively for all adjacents of s
    for(int i = 0; i < g[s].size(); i++) {
        // if adjacent not visited, call dfs on it
        int k = g[s][i];
        if(!vis[k]) {
            dfs(k, g, vis);
        }
    }
}
