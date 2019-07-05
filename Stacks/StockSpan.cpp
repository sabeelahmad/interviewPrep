#include<bits/stdc++.h>
using namespace std;

bool StockSpan(int *prices, int n) {
  stack<int> st;
  // stock span for first day will always be 1, as no element on left of it
  cout << 1 << " ";
  // we push indices to stack, to make it easier to calculate spans
  st.push(0);
  for(int i = 1; i < n; i++) {
    // For each element, we pop previous elements that are consecutively smaller than it
    // if stack becomes empty, all elements on left of it are smaller than it and span is i + 1
    // else, span is i - top of stack, that is the closest element of left greater than it
    while(!st.empty() && prices[st.top()] <= prices[i]) {
      st.pop();
    }
    if(st.empty()) {
      cout << i + 1 << " ";
    } else {
      cout << i - st.top() << " ";
    }

    // push to stack
    st.push(i);
  }
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	   int n;
     cin >> n;
     int prices[n];
     for(int i = 0; i < n; i++) {
       cin >> prices[i];
     }
     StockSpan(prices, n);
     cout << endl;
   	}
	return 0;
}
