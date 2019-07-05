#include<bits/stdc++.h>
using namespace std;

bool sortbysecond(const pair<pair<int, int>,int> &a, const pair<pair<int, int>,int> &b) {
  return (a.first.second < b.first.second);
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	   int n;
     cin >> n;
     int start[n], end[n];
     for(int i = 0; i < n; i++) {
       cin >> start[i];
     }
     for(int i = 0; i < n; i++) {
       cin >> end[i];
     }

     vector < pair< pair< int, int>,  int >> activities;
     for(int i = 0; i < n; i++) {
       pair<int, int> temp;
       temp.first = start[i];
       temp.second = end[i];
       activities.push_back(make_pair(temp, i));
     }
     // We sort activities by finish time, and then for each activity we check if previously processed activity finish overlaps with its start or not
     sort(activities.begin(), activities.end(), sortbysecond);
     int ans = 1;
     pair<int, int> prevProcessed = activities[0].first;
     cout << activities[0].second + 1 << " ";
     for(int i = 1; i < activities.size(); i++) {
       if(activities[i].first.first >= prevProcessed.second) {
         ans++;
         prevProcessed = activities[i].first;
         cout << activities[i].second  + 1 << " ";
       }
     }
     cout << endl;
	}
	return 0;
}
