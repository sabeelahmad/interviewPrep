#include<bits/stdc++.h>
using namespace std;

// Struct to represent cell
struct cell
{
    int x, y;
    int distance;
    cell(int x, int y, int distance) :
        x(x), y(y), distance(distance) {}
};
// Compartor for set to order cells by distance
bool operator<(const cell& a, const cell& b) {
    if(a.distance == b.distance) {
        if(a.x != b.x) {
            return(a.x < b.x);
        } else {
            return(a.y < b.y);
        }
    }
    return(a.distance < b.distance);
}

bool isSafe(int x, int y, int V) {
    if (x >= 0 && y >= 0 && x < V && y < V) {
        return true;
    }
    return false;
}


// We need to modify dijkstra to support 2D matrix
int dijkstra(int** graph, int V) {
    int distance[V][V];
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            distance[i][j] = INT_MAX;
        }
    }
    // neighbors
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    // using set to get minVertex in O(1);
    set<cell> s;
    // insert first cell
    s.insert(cell(0, 0, 0));
    distance[0][0] = graph[0][0];
    // for all vertices
    while(!s.empty()) {
        // get min vertex (at front of set)
        cell k = *s.begin();
        // remove from set
        s.erase(s.begin());
        // if neighbors are safe visit them and relax them
        for(int i = 0; i < 4; i++) {
            int x = k.x + dx[i];
            int y = k.y + dy[i];
            if(!isSafe(x, y, V)) {
                continue;
            }
            // if safe try relaxing
            if(distance[x][y] > distance[k.x][k.y] + graph[x][y]) {
                if(distance[x][y] != INT_MAX) {
                    s.erase(s.find(cell(x, y, distance[x][y])));
                }

                distance[x][y] = distance[k.x][k.y] + graph[x][y];
                s.insert(cell(x, y, distance[x][y]));
            }
        }
    }
    return distance[V-1][V-1];
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
	    // simply apply dijkstra
	    cout << dijkstra(mat, n) << endl;
	}
	return 0;
}
