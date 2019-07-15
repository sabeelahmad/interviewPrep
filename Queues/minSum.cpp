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

     // we use min heap to make two numbers and take sort of greedy approach
     int num_a = 0, num_b = 0;
     priority_queue< int, vector<int>, greater<int> > pq;
     for(int i = 0; i < n; i++) pq.push(a[i]);
     int i = 0;
     while(!pq.empty()) {
       int x = pq.top();
       pq.pop();
       if(i%2 == 0) {
         num_a = (num_a * 10) + x;
       } else {
         num_b = (num_b * 10) + x;
       }
       i++;
     }
     cout << num_a + num_b << endl;
	}
	return 0;
}
