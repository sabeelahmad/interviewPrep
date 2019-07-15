#include<bits/stdc++.h>
using namespace std;
#define M 26

// for circle , we make a graph where first and last alphabets of a string act as vertices
// there should be a loop through all vertices for circle formation
// to check this, in and out degree for each vertex should be same and graph formed should be strongly connected

void dfs(vector<int> g[], vector<bool>& vis, int s) {
    vis[s] = true;
    for(int i = 0; i < g[s].size(); i++) {
        if(!vis[g[s][i]]) {
            dfs(g, vis, g[s][i]);
        }
    }
}

bool isConnected(vector<int> g[], vector<bool>& mark, int s) {
    // visit array
    vector<bool> vis(M, false);
    // perform dfs from s
    dfs(g, vis, s);
    // after one dfs all marked vertices should be visited if not ans is false
    for(int i = 0; i < M; i++) {
        if(mark[i] && !vis[i]) {
            return false;
        }
    }
    return true;
}

bool isCirclePossible(string arr[], int n) {
    // create graph with 26 possible vertices for all aphabets
    vector<int> g[M];
    // mark array initialized to false
    vector<bool> mark(M, false);
    // in degree and out degree array
    vector<int> in(M, 0), out(M, 0);
    // create graph and indegree and outdegree calculations
    for(int i = 0; i < n; i++) {
        // for each string, make an edge from its first char to last
        // add to in and out degrees
        int f = arr[i].front() - 'a';
        int l = arr[i].back() - 'a';
        // mark
        mark[f] = mark[l] = true;
        // add edge
        g[f].push_back(l);
        // add 1 to out of f and 1 to in of l
        out[f]++;
        in[l]++;
    }
    // check if in and outs are same if not return false
    for(int i = 0; i < M; i++) {
        if(in[i] != out[i]) {
            return false;
        }
    }
    // if all ins and outs were same, check for strongly connected
    return isConnected(g, mark, arr[0].front() - 'a');
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    string arr[n];
	    for(int i = 0; i < n; i++) {
	        cin >> arr[i];
	    }
	    cout << isCirclePossible(arr, n) << endl;
	}
	return 0;
}
