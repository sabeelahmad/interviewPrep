#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
int main() {

	int T;
	cin>>T;
	while(T--)
	{
		int N,M;
		cin>>N>>M;
		vector<int> A[N];
		for(int i=0;i<N;i++){
		    vector<int> temp(M);
		    A[i] = temp;
		    for(int j=0;j<M;j++){
		        cin>>A[i][j];
		    }
		}
		cout<<findIslands(A,N,M)<<endl;
	}
	return 0;
}
}
/*This is a function problem.You only need to complete the function given below*/
/*you are required to complete this method*/
/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/
bool isSafe(int x, int y, int N, int M, bool** visited, vector<int> A[]) {
    if(x >= 0 && y >= 0 && x < N && y < M && !visited[x][y] && A[x][y] == 1) {
        return true;
    }
    return false;
}

// we will do dfs in all possible 8 directions if they are not out of bound
void dfs(vector<int> A[], int N, int M, int si, int sj, bool** visited) {
    visited[si][sj] = true;
    if(isSafe(si + 1, sj, N, M, visited, A)) {
        dfs(A, N, M, si + 1, sj, visited);
    }
    if(isSafe(si - 1, sj, N, M, visited, A)) {
        dfs(A, N, M, si - 1, sj, visited);
    }
    if(isSafe(si, sj + 1, N, M, visited, A)) {
        dfs(A, N, M, si, sj + 1, visited);
    }
    if(isSafe(si, sj - 1, N, M, visited, A)) {
        dfs(A, N, M, si, sj - 1, visited);
    }
    if(isSafe(si + 1, sj + 1, N, M, visited, A)) {
        dfs(A, N, M, si + 1, sj + 1, visited);
    }
    if(isSafe(si + 1, sj - 1, N, M, visited, A)) {
        dfs(A, N, M, si + 1, sj - 1, visited);
    }
    if(isSafe(si - 1, sj + 1, N, M, visited, A)) {
        dfs(A, N, M, si - 1, sj + 1, visited);
    }
    if(isSafe(si - 1, sj - 1, N, M, visited, A)) {
        dfs(A, N, M, si - 1, sj - 1, visited);
    }
}

int findIslands(vector<int> A[], int N, int M)
{
    // make visited array of NxM
    bool** visited = new bool*[N];
    for(int i = 0; i < N; i++) {
        visited[i] = new bool[M];
        for(int j = 0; j < M; j++) {
            visited[i][j] = false;
        }
    }
    // now for each 1 in A, call dfs and see how many 1's we can visit
    int count = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(!visited[i][j] && A[i][j] == 1) {
                dfs(A, N, M, i, j, visited);
                count++;
            }
        }
    }
    return count;
}
