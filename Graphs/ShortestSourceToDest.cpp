#include<bits/stdc++.h>
using namespace std;
#define ppi pair< int, pair <int, int> >

bool isSafe(int** graph, int n, int m, int x, int y, bool ** visited) {
    if(x >= 0 && y >= 0 && x < n && y < m && !visited[x][y] && graph[x][y] != 0) {
        return true;
    }
    return false;
}

int bfs(int** graph, int n, int m, int dx, int dy, bool** visited) {
    queue<ppi> q;
    // distance, {x, y}
    q.push(make_pair(0, make_pair(0, 0)));
    while(!q.empty()) {
        // take front of queue
        ppi curr = q.front();
        q.pop();
        int dist = curr.first;
        int x = curr.second.first;
        int y = curr.second.second;
        //cout << x << " " << y << endl;
        visited[x][y] = true;
        // check if curr is destination cell - return distance
        if(x == dx && y == dy) {
            return dist;
        }
        // if not destination, add all 4 directions if safe to queue as its adjacents
        if(isSafe(graph, n, m, x + 1, y, visited)) {
            q.push(make_pair(dist+1, make_pair(x + 1, y)));
        }
        if(isSafe(graph, n, m, x - 1, y, visited)) {
            q.push(make_pair(dist+1, make_pair(x - 1, y)));
        }
        if(isSafe(graph, n, m, x, y + 1, visited)) {
            q.push(make_pair(dist+1, make_pair(x, y + 1)));
        }
        if(isSafe(graph, n, m, x, y - 1, visited)) {
            q.push(make_pair(dist+1, make_pair(x, y - 1)));
        }
    }
    return -1;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	   int n, m;
	   cin >> n >> m;
     int** graph = new int*[n];
 	   for(int i = 0; i < n; i++) {
 	       graph[i] = new int[m];
 	   }
 	   for(int i = 0; i < n; i++) {
 	       for(int j = 0; j < m; j++) {
 	           cin >> graph[i][j];
 	       }
 	   }
	   int dx, dy;
	   cin >> dx >> dy;

	   // visited array
	   bool** visited = new bool*[n];
	   for(int i = 0; i < n; i++) {
	       visited[i] = new bool[m];
	       for(int j = 0; j < m; j++) {
	           visited[i][j] = false;
	       }
	   }

	   // if 0, 0 is not 1
	   if(graph[0][0] == 0) {
	       cout << -1 << endl;
	       continue;
	   }

	   // we need min steps from 0, 0 to dx, dy
	   // bfs traversal of graph always gives shortest path in unweighted graph
	   cout << bfs(graph, n, m, dx, dy, visited) << endl;
	}
	return 0;
}
