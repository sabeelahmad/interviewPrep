#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define MAX 21

void floodfill(char mat[][MAX], int x, int y, int n, int m, char prev, char neww) {
    if(x < 0 || y < 0 || x >= n || y >= m) {
        return;
    }
    // If not '-'
    if(mat[x][y] != prev) {
        return;
    }
    // if '-', replace and recur
    mat[x][y] = neww;
    floodfill(mat, x + 1, y, n, m, prev, neww);
    floodfill(mat, x - 1, y, n, m, prev, neww);
    floodfill(mat, x, y + 1, n, m, prev, neww);
    floodfill(mat, x, y - 1, n, m, prev, neww);
}

void replaceXO(char mat[][MAX], int n, int m) {
    // Replace all O's with '-'
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == 'O') {
                mat[i][j] = '-';
            }
        }
    }

    // Now for all '-' on edges call floodfill and replace them with 'O'
    for(int i = 0; i < m; i++) {
        if(mat[0][i] == '-') {
            floodfill(mat, 0, i, n, m, '-', 'O');
        }
    }
    for(int i = 0; i < m; i++) {
        if(mat[n-1][i] == '-') {
            floodfill(mat, n-1, i, n, m, '-', 'O');
        }
    }
    for(int i = 0; i < n; i++) {
        if(mat[i][0] == '-') {
            floodfill(mat, i, 0, n, m, '-', 'O');
        }
    }
    for(int i = 0; i < n; i++) {
        if(mat[i][m-1] == '-') {
            floodfill(mat, i, m-1, n, m, '-', 'O');
        }
    }

    // Replace remaining '-' with 'X'
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == '-') {
                mat[i][j] = 'X';
            }
        }
    }
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n, m;
	    cin >> n >> m;
	    char mat[MAX][MAX];
	    for(int i = 0; i < n; i++) {
	        for(int j = 0; j < m; j++) {
	            cin >> mat[i][j];
	        }
	    }
	    replaceXO(mat, n, m);
	    for(int i = 0; i < n; i++) {
	        for(int j = 0; j < m; j++) {
	            cout << mat[i][j] << " ";
	        }
	    }
	    cout << endl;
	}
	return 0;
}
