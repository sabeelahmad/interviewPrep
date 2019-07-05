#include <bits/stdc++.h>
using namespace std;

bool unassigned(int soduku[9][9], int &r, int &c) {
    for(int i = 0; i < 9; i++) {
      for(int j = 0; j < 9; j++) {
        if(soduku[i][j] == 0) {
          r = i;
          c = j;
          return true;
        }
      }
    }
    return false;
}

bool isSafe(int soduku[9][9], int r, int c, int num) {
  // Check for same num used in row
  for(int i = 0; i < 9; i++) {
    if(soduku[r][i] == num) {
      return false;
    }
  }

  // Check for same num used in col
  for(int i = 0; i < 9; i++) {
    if(soduku[i][c] == num) {
      return false;
    }
  }

  // Check for the same num in its 3x3 box as well
  r = r - (r%3);
  c = c - (c%3);
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      if(soduku[i + r][j + c] == num) {
        return false;
      }
    }
  }

  // Return true if none of the above cases return false
  return true;
}

bool solveTheSoduku(int soduku[9][9]) {
  // Check for an unassigned position, if no unassigned position soduku is solved
  int row, col;
  if(!unassigned(soduku, row, col)) {
    return true;
  }

  // We now have the cell position of the unassigned cell, we try to put numbers from 1 - 9 one by one at it but first we check if it is safe to put the number
  for(int num = 1; num <= 9; num++) {
    if(isSafe(soduku, row, col, num)) {
      soduku[row][col] = num;
      // check if placing this num leads to solution
      if(solveTheSoduku(soduku)) {
        return true;
      }
      // if it doesnt, remove the current num assignment, and assign next
      soduku[row][col] = 0;
    }
  }
  return false; // trigger backtracking
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int soduku[9][9];
    for(int i = 0; i < 9; i++) {
      for(int j = 0; j < 9; j++) {
        cin >> soduku[i][j];
      }
    }
    solveTheSoduku(soduku);
    // Print solved soduku
    for(int i = 0; i < 9; i++) {
      for(int j = 0; j < 9; j++) {
        cout << soduku[i][j] << " ";
      }
      cout << endl;
    }
  }
}
