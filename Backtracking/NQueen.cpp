#include<bits/stdc++.h>
using namespace std;
#define MAX 20

bool isSafe(int board[MAX][MAX], int col, int row, int n) {
  // check left side of row
  for(int i = 0; i < col; i++) {
    if(board[row][i]) {
      return false;
    }
  }

  // check left upper diagonal
  for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
    if(board[i][j]) {
      return false;
    }
  }

  // check left lower diagona
  for(int i = row, j = col; i < n && j >= 0; i++, j--) {
    if(board[i][j]) {
      return false;
    }
  }
}

void printSolutionFormat(int board[MAX][MAX], int n) {
  cout << "[";
  for(int col = 0; col < n; col++) {
    for(int row = 0; row < n; row++) {
      if(board[row][col]) {
        cout << row + 1 << " ";
      }
    }
  }
  cout << "]" << " ";
}

bool solveNQueenUtil(int board[MAX][MAX], int n, int col) {
  // If all queens placed
  if(col == n) {
    printSolutionFormat(board, n);
    return true;
  }

  bool res = false;
  // Start placing queen in each row of current col
  for(int i = 0; i < n; i++) {
    // check if current row in current col is safe
    if(isSafe(board, col, i, n)) {
      // place queen
      board[i][col] = 1;
      // see if this placement gets an answer recursively
      res = solveNQueenUtil(board, n, col + 1) || res;
      // remove queen and try another possibility
      board[i][col] = 0;
    }
  }
  return res;
}

void solveNQueen(int n) {
  int board[MAX][MAX];
  memset(board, 0, sizeof(board));
  if(!solveNQueenUtil(board, n, 0)) {
    cout << -1 << endl;
  }
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	   int n;
     cin >> n;
     solveNQueen(n);
     cout << endl;
	}
	return 0;
}
