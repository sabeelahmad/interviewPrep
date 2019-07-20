#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define pii pair<int, int>
#define ppi pair<int, pair<int, int>>

bool isValid(int x, int y, int n, int m) {
    return (x >= 1 && y >= 1 && x <= n && y <= m);
}

int knightWalk(pii start, pii dest, int n, int m) {
    // Shortest path in graph can be found using bfs

    bool visited[n + 1][m + 1];
    memset(visited, false, sizeof(visited));

    int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

    queue<ppi> q;
    q.push({0, {start.first, start.second}});
    visited[start.first][start.second] = true;
    while(!q.empty()) {
        // Get front of queue
        ppi f = q.front();
        q.pop();
        int x = f.second.first;
        int y = f.second.second;
        int dist = f.first;
        // Check if it is destination, if yes return distance
        if(x == dest.first && y == dest.second) {
            return dist;
        }
        // if not dist, try all valid moves of knight
        for(int i = 0; i < 8; i++) {
            int t_x = x + dx[i];
            int t_y = y + dy[i];
            if(isValid(t_x, t_y, n, m) && !visited[t_x][t_y]) {
                visited[t_x][t_y] = true;
                q.push({dist + 1, {t_x, t_y}});
            }
        }
    }
    // if queue becomes empty and destiantion not reached, ans is -1
    return -1;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n, m;
	    cin >> n >> m;
	    pii start, dest;
	    cin >> start.first >> start.second >> dest.first >> dest.second;
	    cout << knightWalk(start, dest, n, m) << endl;
	}
	return 0;
}
