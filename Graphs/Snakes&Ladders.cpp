#include<bits/stdc++.h>
using namespace std;

int bfs(int moves[], int n) {
    // we will do normal bfs but in queue maintain the distance of a cell posn from source (1)
    // and push into queue according if a snake or ladder is found
    bool visited[n];
    memset(visited, false, sizeof(visited));

    queue<pair<int, int>> q;
    visited[1] = true;
    q.push({1, 0});

    pair<int, int> x;
    while(!q.empty()) {
        // get front of queue
        x = q.front();
        q.pop();
        // check if this cell is destination, if yes return its dist
        if(x.first == n - 1) {
            break;
        }
        // if not dest, try all 6 possible vertices from this cell
        for(int j = x.first + 1; j <= (x.first + 6) && j < n; j++) {
            // if not visited, visit it and push to queue
            if(!visited[j]) {
                visited[j] = true;
                pair<int, int> t;
                t.second = x.second + 1;
                // see where we can reach from this cell
                if(moves[j] != -1) {
                    t.first = moves[j];
                } else {
                    t.first = j;
                }
                q.push(t);
            }
        }
    }
    return x.second;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    int moves[31];
	    memset(moves, -1, sizeof(moves));
	    for(int i = 0; i < n; i++) {
	        int x, y;
	        cin >> x >> y;
	        moves[x] = y;
	    }
	    // we will do a simple bfs, consider all edges as same weights
	    // we will maintain a distance and parameter where we can reach on from a particular cell
	    cout << bfs(moves, 31) << endl;
	}
	return 0;
}
