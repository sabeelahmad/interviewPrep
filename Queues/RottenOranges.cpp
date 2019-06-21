// Using queue and delimiter technique : https://www.geeksforgeeks.org/minimum-time-required-so-that-all-oranges-become-rotten

#include <bits/stdc++.h>
using namespace std;

bool inBounds(int x, int y, int n, int m) {
  return(x >= 0 && y >= 0 && x < n && y < m);
}

bool isDelimiter(pair<int, int> p) {
  return (p.first == -1 && p.second == -1);
}

int getTimeToRot(int arr[101][101], int n, int m) {
  // we will use (-1,-1) as delimiter for current orange time frame
  queue< pair<int, int> > q;
  pair<int, int> temp;
  int ans = 0;

  // storing all rotten oranges in first time frame
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(arr[i][j] == 2) {
        temp.first = i;
        temp.second = j;
        q.push(temp);
      }
    }
  }

  // add delimiter for first time frame
  temp.first = -1;
  temp.second = -1;
  q.push(temp);

  while(!q.empty()) {
    bool flag = false; // using to see if any further oranges are rotten

    // till delimeter not found
    while(!isDelimiter(q.front())) {
      // get current orange
      temp = q.front();
      // a rotten orange can rot left, right, up, down oranges but x,y should be within bounds and should be fresh in order to be rotten
      if(inBounds(temp.first + 1, temp.second, n, m) && arr[temp.first + 1][temp.second] == 1) {
        // if this is first orange to be rotten in current time frame - increase it, we do this to increase ans only once for a time frame
        if(!flag) {
          ans++;
        }
        flag = true;
        arr[temp.first + 1][temp.second] = 2;
        // push new to queue
        temp.first++;
        q.push(temp);
        // back to current cell
        temp.first--;
      }
      if(inBounds(temp.first - 1, temp.second, n, m) && arr[temp.first - 1][temp.second] == 1) {
        if(!flag) {
          ans++;
        }
        flag = true;
        arr[temp.first - 1][temp.second] = 2;
        // push new to queue
        temp.first--;
        q.push(temp);
        // back to current cell
        temp.first++;
      }
      if(inBounds(temp.first, temp.second + 1, n, m) && arr[temp.first][temp.second + 1] == 1) {
        if(!flag) {
          ans++;
        }
        flag = true;
        arr[temp.first][temp.second + 1] = 2;
        // push new to queue
        temp.second++;
        q.push(temp);
        // back to current cell
        temp.second--;
      }
      if(inBounds(temp.first, temp.second - 1, n, m) && arr[temp.first][temp.second - 1] == 1) {
        if(!flag) {
          ans++;
        }
        flag = true;
        arr[temp.first][temp.second - 1] = 2;
        // push new to queue
        temp.second--;
        q.push(temp);
        // back to current cell
        temp.second++;
      }
      q.pop(); // pop current orange
    }
    // pop delimeter
    q.pop();

    // if q not empty means more oranges rotten add new delimeter for new time frame
    if(!q.empty()) {
      temp.first = -1;
      temp.second = -1;
      q.push(temp);
    }
  }

  // check if any fresh orange remain, if yes ans is -1, else ans is ans
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(arr[i][j] == 1) {
        return -1;
      }
    }
  }
  return ans;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n, m;
    cin >> n >> m;
    int a[101][101];
    for(int i = 0; i < n; i++ ) {
      for(int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    cout << getTimeToRot(a, n, m) << endl;
  }
}
