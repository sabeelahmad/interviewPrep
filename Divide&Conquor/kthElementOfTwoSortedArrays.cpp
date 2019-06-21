#include<iostream>
using namespace std;

int merge(int* a, int* b, int n, int m, int k) {
    int i = 0, j = 0;
    while(i < n && j < m) {
        int cr;
        if(a[i] < b[j]) {
            cr = a[i];
            i++;
        } else {
            cr = b[j];
            j++;
        }
        k--;
        if(k == 0) {
            return cr;
        }
    }
    while(i < n) {
        k--;
        if(k == 0) {
            return a[i];
        }
        i++;
    }
    while(j < m) {
        k--;
        if(k == 0) {
            return b[j];
        }
        j++;
    }
}

int main()
 {
	int t;
	cin >> t;
	while(t--) {
	    int n, m, k;
	    cin >> n >> m >> k;
	    int a[n], b[m];
	    for(int i = 0; i < n; i++) {
	        cin >> a[i];
	    }
	    for(int i = 0; i < m; i++) {
	        cin >> b[i];
	    }

	    // merge
	    cout << merge(a, b, n, m, k) << endl;
	}
	return 0;
}
