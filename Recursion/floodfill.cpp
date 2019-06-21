#include<bits/stdc++.h>
using namespace std;

void floodfill(int arr[1010][1010], int rows, int cols, int x, int y, int oc, int color) {
    if(x < 0 || y < 0 || x == rows || y == cols) {
        return; // out of bounds of matrix
    }
    arr[x][y] = color;
    if(arr[x][y - 1] == oc)
        floodfill(arr, rows, cols, x, y - 1, oc, color); // left
    if(arr[x][y + 1] == oc)
        floodfill(arr, rows, cols, x, y + 1, oc, color); // right
    if(arr[x - 1][y] == oc)
        floodfill(arr, rows, cols, x - 1, y, oc, color); // up
    if(arr[x + 1][y] == oc)
        floodfill(arr, rows, cols, x + 1, y, oc, color); // down
}

int main()
{
	int t;
	cin >> t;
	while(t--) {
	    int n, m;
	    cin >> n >> m;
	    int x, y, color;
	    int arr[1010][1010];
	    for(int i = 0; i < n; i++) {
	        for(int j = 0; j < m; j++) {
	            cin >> arr[i][j];
	        }
	    }
	    cin >> x >> y >> color;
	    int oldcolor = arr[x][y];
	    floodfill(arr, n, m, x, y, oldcolor, color);
	    for(int i = 0; i < n; i++) {
	        for(int j = 0; j < m; j++) {
	            cout << arr[i][j] << " ";
	        }
	        //cout << endl;
	    }
	    cout << endl;
	}
	return 0;
}
