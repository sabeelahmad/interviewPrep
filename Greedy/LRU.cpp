#include<bits/stdc++.h>
using namespace std;

int pageFaults(int* a, int n, int capacity) {
  int page_faults = 0;
  // We use a set to keep track of pages currently in memory
  set<int> s;
  s.clear();

  // we use a map to keep track of indices of pages to get least recently used
  unordered_map<int, int> umap;
  umap.clear();

  for(int i = 0; i < n; i++) {
    // if set contains less pages than capacity simply insert if not already present
    if(s.size() < capacity) {
      if(s.find(a[i]) == s.end()) {
        page_faults++;
        s.insert(a[i]);
      }
      // add to map the lru index irrespective of if it was already present in it or not
      umap[a[i]] = i;
    } else {
      // if set is full and page not in it , remove least recently used, that is min index in map, add new page to set ,incr ans
      if(s.find(a[i]) == s.end()) {
        page_faults++;
        // get lru page
        int lru = INT_MAX, val;
        for(auto it = s.begin(); it != s.end(); it++) {
          if(umap[*it] < lru) {
            lru = umap[*it];
            val = *it;
          }
        }

        // remove this page from set
        s.erase(val);
        // add new page to set
        s.insert(a[i]);
      }
    }
    // add to map the lru indexed of curr page
    umap[a[i]] = i;
  }
  return page_faults;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	   int n, capacity;
     cin >> n;
     int a[n];
     for(int i = 0; i < n; i++) {
       cin >> a[i];
     }
     cin >> capacity;
     cout << pageFaults(a, n, capacity) << endl;
	}
	return 0;
}
