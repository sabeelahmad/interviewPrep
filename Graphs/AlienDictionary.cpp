#include<bits/stdc++.h>
using namespace std;
string printOrder(string [], int , int );
string order;
bool f(string a,string b)
{
	int p1=0;int p2=0;
	for(int i=0;i<min(a.size(),b.size()) and p1 ==p2;i++ )
	{
		p1 = order.find(a[i]);
		p2 = order.find(b[i]);
	//	cout<<p1<<" "<<p2<<endl;
	}

	if(p1 == p2 and a.size()!=b.size())
	return a.size()<b.size();

	return p1<p2;
}

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
    string s[n];
    for(int i=0;i<n;i++)cin>>s[i];

        string ss = printOrder(s,n,k);
        order="";
        for(int i=0;i<ss.size();i++)
        order+=ss[i];

        string temp[n];
        std::copy(s, s + n, temp);
        sort(temp,temp+n,f);

        bool f= true;
        for(int i=0;i<n;i++)
        if(s[i]!=temp[i])f=false;

        cout<<f;
        cout<<endl;

    }
	return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
/*The function should return a string denoting the
order of the words in the Alien Dictionary */
class Graph {
  int V;
  vector<int> *adj;

  void topologicalSortHelper(int src, stack<int>& s, vector<bool>& visited) {
      visited[src] = true;
      for(int i = 0; i < adj[src].size(); i++) {
          int k = adj[src][i];
          if(!visited[k]) {
              topologicalSortHelper(k, s, visited);
          }
      }
      // add to stack after all dependents added
      s.push(src);
  }

  public:
    Graph(int V) {
        this->V = V;
        adj = new vector<int>[V];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    string topologicalSort() {
        stack<int> s;
        vector<bool> vis(V, false);
        // consider disconnected graph as well
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                topologicalSortHelper(i, s, vis);
            }
        }

        string x = "";
        while(!s.empty()) {
            x += (s.top() + 'a');
            s.pop();
        }
        return x;
    }
};

string printOrder(string dict[], int N, int k)
{
   // We consider each pair of strings and when a mismatch occurs we add edge to graph
   // basically to create a dependecny order of a kind
   // After the graph is formed we simply perform a topological sort to get the answer

   // Create graph with K vertices (No of alphabets in alien language)
   Graph g(k);
   for(int i = 0; i < N - 1; i++) {
       string word1 = dict[i];
       string word2 = dict[i + 1];
       for(int j = 0; j < min(word1.length(), word2.length()); j++) {
           if(word1[j] != word2[j]) {
               // mismatch! add edge to graph
               g.addEdge(word1[j] - 'a', word2[j] - 'a');
               break;
           }
       }
   }

   // now call topological sort
   return g.topologicalSort();
}
