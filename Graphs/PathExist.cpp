#include<bits/stdc++.h>
using namespace std;

bool isSafe(int** mat, int n, int x, int y, bool** visited) {
    if(x >= 0 && y >= 0 && x < n && y < n && !visited[x][y] && mat[x][y] != 0) {
        return true;
    }
    return false;
}

bool dfs(int** mat, int n, int sx, int sy, bool** visited) {
    // mark this posn as visited
    //cout << sx << " " << sy << " called" << endl;
    visited[sx][sy] = true;
    // if destination reached, return rue
    if(mat[sx][sy] == 2) {
        return true;
    }
    // call for all other 4 directions, if safe
    if(isSafe(mat, n, sx + 1, sy, visited) && dfs(mat, n, sx + 1, sy, visited)) {
        return true;
    }
    if(isSafe(mat, n, sx - 1, sy, visited) && dfs(mat, n, sx - 1, sy, visited)) {
        return true;
    }
    if(isSafe(mat, n, sx, sy + 1, visited) && dfs(mat, n, sx, sy + 1, visited)) {
        return true;
    }
    if(isSafe(mat, n, sx, sy - 1, visited) && dfs(mat, n, sx, sy - 1, visited)) {
        return true;
    }

    // if dont get answer from any direction, return false;
    return false;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    int** mat = new int*[n];
	    for(int i = 0; i < n; i++) {
	        mat[i] = new int[n];
	    }
	    for(int i = 0; i < n; i++) {
	        for(int j = 0; j < n; j++) {
	            cin >> mat[i][j];
	        }
	    }
	    bool** visited = new bool*[n];
	    for(int i = 0; i < n; i++) {
	        visited[i] = new bool[n];
	        for(int j = 0; j < n; j++) {
	            visited[i][j] = false;
	        }
	    }
	    // find source
	    int x, y;
	    for(int i = 0; i < n; i++) {
	        for(int j = 0; j < n; j++) {
	            if(mat[i][j] == 1) {
	                x = i;
	                y = j;
	                break;
	            }
	        }
	    }
      //cout << x << " " << y << endl;
	    cout << dfs(mat, n, x, y, visited) << endl;
	}
	return 0;
}
