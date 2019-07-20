#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define MAX 51

bool isSafe(int graph[MAX][MAX], int x, int y, int n, int m, int& temp, bool visited[MAX][MAX]) {
    if(x >= 0 && y >= 0 && x < n && y < m && graph[x][y] && !visited[x][y]) {
        return true;
    }
    return false;
}

void dfs(int graph[MAX][MAX], int x, int y, int n, int m, int& temp, bool visited[MAX][MAX]) {
    visited[x][y] = true;
    temp++;
    // Try visiting all 8 possiblities
    if(isSafe(graph, x + 1, y, n, m, temp, visited)) {
        dfs(graph, x + 1, y, n, m, temp, visited);
    }
    if(isSafe(graph, x - 1, y, n, m, temp, visited)) {
        dfs(graph, x - 1, y, n, m, temp, visited);
    }
    if(isSafe(graph, x, y + 1, n, m, temp, visited)) {
        dfs(graph, x, y + 1, n, m, temp, visited);
    }
    if(isSafe(graph, x, y - 1, n, m, temp, visited)) {
        dfs(graph, x, y - 1, n, m, temp, visited);
    }
    if(isSafe(graph, x + 1, y + 1, n, m, temp, visited)) {
        dfs(graph, x + 1, y + 1, n, m, temp, visited);
    }
    if(isSafe(graph, x + 1, y - 1, n, m, temp, visited)) {
        dfs(graph, x + 1, y - 1, n, m, temp, visited);
    }
    if(isSafe(graph, x - 1, y + 1, n, m, temp, visited)) {
        dfs(graph, x - 1, y + 1, n, m, temp, visited);
    }
    if(isSafe(graph, x - 1, y - 1, n, m, temp, visited)) {
        dfs(graph, x - 1, y - 1, n, m, temp, visited);
    }
}

int largestRegion(int graph[MAX][MAX], int n, int m) {
    // Visited array
    bool visited[MAX][MAX];
    memset(visited, false, sizeof(visited));

    // we simply find a 1 and call dfs on it and count how many one's are reachable
    // we do this for all components and get max
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(graph[i][j] && !visited[i][j]) {
                int temp = 0;
                dfs(graph, i, j, n, m, temp, visited);
                ans = max(ans, temp);
            }
        }
    }
    return ans;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n, m;
	    cin >> n >> m;
	    int graph[MAX][MAX];
	    for(int i = 0; i < n; i++) {
	        for(int j = 0; j < m; j++) {
	            cin >> graph[i][j];
	        }
	    }
	    cout << largestRegion(graph, n, m) << endl;
	}
	return 0;
}
