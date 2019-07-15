#include<iostream>
using namespace std;

int merge(int* a1, int* a2, int n) {
    int sum = 0;
    int i = 0, j = 0;
    int count = 0;
    while(i < n && j < n) {
        int cr;
        if(a1[i] < a2[j]) {
            cr = a1[i];
            i++;
        } else {
            cr = a2[j];
            j++;
        }
        count++;
        if(count == n + 1) {
            sum += cr;
            return sum;
        }
        if(count == n) {
            sum += cr;
        }
    }
}

int main()
 {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    int a1[n], a2[n];
	    for(int i = 0; i < n; i++) {
	        cin >> a1[i];
	    }
	    for(int i = 0; i < n; i++) {
	        cin >> a2[i];
	    }
	    cout << merge(a1, a2, n) << endl;
	}
	return 0;
}
