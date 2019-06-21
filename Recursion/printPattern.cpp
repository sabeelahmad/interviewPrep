#include<bits/stdc++.h>
using namespace std;

void printPattern(int n, int next, bool neg) {
    if(next == n && !neg) {
      cout << next << endl;
      return;
    }

    cout << next << " ";

    if(neg && next > 0) {
      printPattern(n, next - 5, true);
    }  else {
      printPattern(n, next + 5, false);
    }
}

int main()
 {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
      bool neg = true;
	    printPattern(n, n, neg);
	}
	return 0;
}
