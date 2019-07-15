#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	   int n;
     cin >> n;
     int a[n];
     for(int i = 0; i < n; i++) {
       cin >> a[i];
     }

     // we will use simply greedy approach and use min heap
     // join first two elements we get from min heap and push their sum to heap till it becomes empty and keep adding to cost

     // min heap
     priority_queue< int, vector<int>, greater<int> > pq;
     for(int i = 0; i < n; i++) {
       pq.push(a[i]);
     }
     long long cost = 0;
     while(!pq.empty()) {
       int a = pq.top();
       pq.pop();
       int b = pq.top();
       pq.pop();
       cost += (a + b);
       if(!pq.empty())
        pq.push(a+b);
       //cout << cost << endl;
     }
     cout << cost << endl;
	}
	return 0;
}
