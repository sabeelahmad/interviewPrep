#include<bits/stdc++.h>
using namespace std;
void dijkstra(vector<vector<int>> , int ,int );
int main()
{
    int t;
    int V;
    cin>>t;
    while(t--){
        cin>>V;

        vector<vector<int>> g(V);

        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }

        for(int i=0;i<V;i++)
        {
      	    for(int j=0;j<V;j++)
      	    {
      		    cin>>g[i][j];
      	    }
        }

        int s;
        cin>>s;

        dijkstra(g, s, V);
        cout<<endl;
       }
        return 0;
}
}
/*This is a function problem.You only need to complete the function given below*/
/*  Function to implement Dijkstra
*   graph: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/
int getMinVertex(int distance[], int V, bool visited[]) {
    int minVal = INT_MAX;
    int minVertex;
    for(int i = 0; i < V; i++) {
        if(distance[i] < minVal && !visited[i]) {
            minVal = distance[i];
            minVertex = i;
        }
    }
    return minVertex;
}

void dijkstra(vector<vector<int>> graph, int src, int V)
{
    // array for distances
    int distance[V];
    // array for visited
    bool visited[V];
    // intialize
    //memset(distance, INT_MAX, sizeof(distance));
    memset(visited, false, sizeof(visited));
    // distance of src to src is 0
    for(int i = 0; i < V; i++) distance[i] = INT_MAX;
    distance[src] = 0;
    // now for each vertex, get min vertex and then relax neighbors
    // first time min vertex will always be src
    for(int i = 0; i < V; i++) {
        int minVertex = getMinVertex(distance, V, visited);
        // mark it visited
        visited[minVertex] = true;
        //cout << minVertex << endl;
        // explore its neighbors
        for(int j = 0; j < V; j++) {
            if(!visited[j] && graph[minVertex][j] != 0 && distance[minVertex] + graph[minVertex][j] < distance[j]) {
                distance[j] = distance[minVertex] + graph[minVertex][j];
            }
        }
    }
    for(int i = 0; i < V; i++) cout << distance[i] << " ";
}
