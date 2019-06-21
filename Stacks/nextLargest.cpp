#include<bits/stdc++.h>
using namespace std;

void printNextGreatestElement(long long * arr, int n) {
    // we will use a stack to solve this question
    // and store nge for each arr[i] in a map so that we can print in order of input
    stack<long long> s;
    unordered_map<long long, long long> m;
    // push first element in stack
    s.push(arr[0]);
    for(int i = 1; i < n; i++) {
        // pick next element and for all elements in stack currently
        // check if its their nge
        // after checked for all , push it into stack
        while(!s.empty() && s.top() < arr[i]) {
            m[s.top()] = arr[i];
            // pop s.top
            s.pop();
        }
        // push current element in stack
        s.push(arr[i]);
    }
    // if some elements still in stack, means their nge is -1
    while(!s.empty()) {
        m[s.top()] = -1;
        s.pop();
    }

    // print
    for(int i = 0; i < n; i++) {
        cout << m[arr[i]] << " ";
    }
}

int main()
 {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    long long * arr = new long long[n];
	    for(int i = 0; i < n; i++) {
	        cin >> arr[i];
	    }
	    printNextGreatestElement(arr, n);
	    cout << endl;
	}
	return 0;
}
