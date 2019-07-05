#include<bits/stdc++.h>
using namespace std;

bool isSafe(char ** boggle, char currChar, int x, int y, int n, int m, int ** visited) {
  if(x >= 0 && y >= 0 && x < n && y < m && visited[x][y] == 0 && boggle[x][y] == currChar) {
    return true;
  }
  return false;
}

bool findInBoggleUtil(char ** boggle, string word, int x, int y, int n, int m, string current, int ** visited) {

    //cout << x << " " << y << " " << word << endl;

    if(word.length() == 1 && isSafe(boggle, word[0], x, y, n, m, visited)) {
      return true;
    }

    // Check if current cell is safe
    if(isSafe(boggle, word[0], x, y, n, m, visited)) {
      // if safe, mark visited
      visited[x][y] = 1;
      // call in all 8 adjacent directions
      if(findInBoggleUtil(boggle, word.substr(1), x + 1, y, n, m, current, visited))
        return true;
      if(findInBoggleUtil(boggle, word.substr(1), x - 1, y, n, m, current, visited))
        return true;
      if(findInBoggleUtil(boggle, word.substr(1), x, y + 1, n, m, current, visited))
        return true;
      if(findInBoggleUtil(boggle, word.substr(1), x, y - 1, n, m, current, visited))
        return true;
      if(findInBoggleUtil(boggle, word.substr(1), x - 1, y - 1, n, m, current, visited))
        return true;
      if(findInBoggleUtil(boggle, word.substr(1), x - 1, y + 1, n, m, current, visited))
        return true;
      if(findInBoggleUtil(boggle, word.substr(1), x + 1, y + 1, n, m, current, visited))
        return true;
      if(findInBoggleUtil(boggle, word.substr(1), x + 1, y - 1, n, m, current, visited))
        return true;
      // now mark unvisited
      visited[x][y] = 0;
    }

    // if not safe return false or dont get true from any where
    return false;
}

bool findInBoggle(char ** boggle, string word, int x, int y, int n, int m, set<string> & wordsFormed) {
  string current = "";
  int ** visited = new int*[n];
  for(int i = 0; i < n; i++) {
    visited[i] = new int[m];
    for(int j = 0; j < m; j++) {
      visited[i][j] = 0;
    }
  }
  if(findInBoggleUtil(boggle, word, x, y, n, m, current, visited)) {
    wordsFormed.insert(word);
    return true;
  } else {
    return false;
  }
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	   int x;
     cin >> x;
     string dict[x];
     for(int i = 0; i < x; i++) {
       cin >> dict[i];
     }
     int n, m;
     cin >> n >> m;
     char ** boggle = new char*[n];
     for(int i = 0; i < n; i++) {
       boggle[i] = new char[m];
     }
     for(int i = 0; i < n; i++) {
       for(int j = 0; j < m; j++) {
         cin >> boggle[i][j];
       }
     }

     set<string> wordsFormed;
     // For each word in dict, find its first char in boggle, and then check if its possible to complete the word
     for(int i = 0; i < x; i++) {
       bool found = false;
       string currWord = dict[i];
       for(int j = 0; j < n; j++) {
         for(int k = 0; k < m; k++) {
           if(boggle[j][k] == currWord[0]) {
             //cout << currWord << " " << j << " " << k << endl;
             if(findInBoggle(boggle, currWord, j, k, n, m, wordsFormed)) {
               found = true;
                break;
             }
           }
         }
         if(found) {
           break;
         }
       }
     }

     if(wordsFormed.size() == 0) {
       cout << -1 << endl;
       continue;
     }

     //sort(wordsFormed.begin(), wordsFormed.end());
     set <string> :: iterator it;
     //it = wordsFormed.begin();
     for(it = wordsFormed.begin(); it != wordsFormed.end(); it++) {
       cout << *it << " ";
     }
     cout << endl;
	}
	return 0;
}
