#include<bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
bool check(int V, int* res, vector<int> adj[]){
    bool flag =true;
    for(int i=0;i<V && flag;i++)
    {
        int n=adj[res[i]].size();
        for(auto j : adj[res[i]])
        {
            for(int k=i+1;k<V;k++)
            {
                if(res[k]==j )
                    n--;
            }
        }
        if(n!=0)
            flag =false;
    }
    if(flag==false)
        return 0;
    return 1;
}
// Driver Code
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,E;
        cin>>E>>N;
        int u,v;

        vector<int> adj[N];

        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
        }

        int *res = topoSort(N, adj);

        cout<<check(N, res, adj)<<endl;

    }
}

}
/*This is a function problem.You only need to complete the function given below*/
// The Graph structure is as folows
/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*   NOTE: You must return dynamically allocated array
*/
void topoSortUtil(int V, vector<int> adj[], stack<int> &st, int s, bool vis[]) {
    vis[s] = true;
    for(int i = 0; i < adj[s].size(); i++) {
        int k = adj[s][i];
        if(!vis[k]) {
            topoSortUtil(V, adj, st, k, vis);
        }
    }
    // push node to stack now
    st.push(s);
}

int* topoSort(int V, vector<int> adj[])
{
   // We make a stack and for each node first push all adjancents to it, then the node by doing dfs
   stack<int> st;
   bool vis[V];
   memset(vis, false, sizeof(vis));
   for(int i = 0; i < V; i++) {
       if(!vis[i]) {
           topoSortUtil(V, adj, st, i, vis);
       }
   }

   int* topo = new int[V];
   int i = 0;
   while(!st.empty()) {
       topo[i++] = st.top();
       st.pop();
   }
   return topo;
}
