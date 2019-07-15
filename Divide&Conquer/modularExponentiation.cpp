#include<bits/stdc++.h>
using namespace std;

int exponentMod(int A, int B, int C) {
    // if base 0
    if(A == 0) {
        return 0;
    }
    // if power 0
    if(B == 0) {
        return 1;
    }

    long y;
    // case 1: B is even, y = (a*b^2)**2
    if(B % 2 == 0) {
        y = exponentMod(A, B/2, C);
        y = (y * y) % C;
    }
    // case 2: B is odd, y = (A * (A^B-1))%C
    else {
        y = A % C;
        y = (y * exponentMod(A, B - 1, C) % C) % C;
    }

    return (int)((y + C)%C);
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int A, B, C;
	    cin >> A >> B >> C;
	    cout << exponentMod(A, B, C) << endl;
	}
	return 0;
}
