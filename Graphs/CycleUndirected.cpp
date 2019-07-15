#include<bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;

        // array of vectors to represent graph
        vector<int> adj[V];

        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;

            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout << isCyclic(adj, V)<<endl;
    }
}

}
/*This is a function problem.You only need to complete the function given below*/
/* This function is used to detect a cycle in undirected graph
*  adj[]: array of vectors to represent graph
*  V: number of vertices
*/
bool dfs(vector<int> adj[], int V, int s, int parent, bool vis[]) {
    vis[s] = true;
    for(int i = 0; i < adj[s].size(); i++) {
        int k = adj[s][i];
        if(vis[k] && k != parent) {
            return true;
        }
        else if(!vis[k]) {
            if(dfs(adj, V, k, s, vis)) {
                return true;
            }
        }
    }
    return false;
}

bool isCyclic(vector<int> adj[], int V)
{
   // we can perform a dfs with extra check that if adjacent is visited and not parent
   // we have a cycle
   // parent for first vertex is -1
   bool vis[V];
   memset(vis, false, sizeof(vis));
   // graphs can be disconnected
   for(int i = 0; i < V; i++) {
     if(!vis[i]) {
         if(dfs(adj, V, i, -1, vis)) {
            return true;
         }
     }
   }
   return false;

}
