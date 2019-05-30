#include<iostream>
using namespace std;
int main()
 {
	//code
    int t;
    cin >> t;
    while(t--) {
        int m, n;
        cin >> m >> n;
        int mat[m][n];
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cin >> mat[i][j];
            }
        }
        int row[m] = {0};
        int col[n] = {0};
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 1) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(row[i] == 1 || col[j] == 1) {
                    mat[i][j] = 1;
                }
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
}
