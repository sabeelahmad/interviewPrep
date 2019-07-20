#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define pb push_back

bool dfs(vector<int> graph[], int N, int s, bool visited[], int count = 0) {
    // If final vertex reached
    if(count == N - 1) {
        // all vertices visited
        return true;
    }
    for(int i = 0; i < graph[s].size(); i++) {
        int k = graph[s][i];
        if(!visited[k]) {
            visited[k] = true;
            if(dfs(graph, N, k, visited, count + 1)) {
                return true;
            }
            visited[k] = false;
        }
    }
    return false;
}

bool isHamiltonian(vector<int> graph[], int N) {
    bool visited[N];
    memset(visited, false, sizeof(visited));

    for(int i = 0; i < N; i++) {
        visited[i] = true;
        if(dfs(graph, N, i, visited)) {
            return true;
        }
        // else start from some other node
        memset(visited, false, sizeof(visited));
    }
    return false;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n, e;
	    cin >> n >> e;
	    vector<int> graph[n];
	    for(int i = 0; i < e; i++) {
	        int u, v;
	        cin >> u >> v;
	        // Undirected Graph
	        graph[u - 1].pb(v - 1);
	        graph[v - 1].pb(u - 1);
	    }
	    int N = n;
	    cout << isHamiltonian(graph, N) << endl;
	}
	return 0;
}
