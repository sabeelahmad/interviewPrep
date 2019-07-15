#include<bits/stdc++.h>
using namespace std;
#define INF 1e7
#define MAX 101

void floydWarshall(int graph[][MAX], int V) {
    // Initialize the distance answer same as graph
    int distance[V][V];
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            distance[i][j] = graph[i][j];
        }
    }

    // now one by one consider each vertex as intermediate while travelling from i to j
    // and try relaxing
    for(int k = 0; k < V; k++) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }

    // print solution
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if(distance[i][j] == INF) {
                cout << "INF" << " ";
            } else {
                cout << distance[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int V;
	    cin >> V;
	    int graph[MAX][MAX];
	    for(int i = 0; i < V; i++) {
	        for(int j = 0; j < V; j++) {
	            cin >> graph[i][j];
	        }
	    }

	    floydWarshall(graph, V);
	}
	return 0;
}
