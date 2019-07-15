#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll maxAreaUnderHist(ll *hist, int n) {
  // for each element we treat it as smallest bar in rectangle, and calcualte areas, max of all these areas is answer
  // to calculate this area, for each bar we get smaller ele index on left and right and then calculate it
  stack<int> s;
  ll max_area = 0, area_with_top, tp;

  int i = 0;
  while(i < n) {
    // if area of hist[i] is greater than top of hist, we add it to stack
    if(s.empty() || hist[s.top()] <= hist[i]) {
      s.push(i);
      i++;
    }
    // if area of hist[s.top()] greater than hist[i], we pop it and calculate its area as if its smaller bar in rectangle
    // right index for it is i, left index (if any) is just the element below it on stack
    else {
      tp = s.top();
      s.pop();
      area_with_top = hist[tp] * (s.empty() ? i: i - s.top() - 1);
      if(area_with_top > max_area) {
        max_area = area_with_top;
      }
    }
  }
  // for remaining elements calculate area as if they are smallest element in rect
  while(!s.empty()) {
    tp = s.top();
    s.pop();
    area_with_top = hist[tp] * (s.empty() ? i: i - s.top() - 1);
    if(area_with_top > max_area) {
      max_area = area_with_top;
    }
  }
  return max_area;
}


int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    ll hist[n];
    for(int i = 0; i < n; i++) {
      cin >> hist[i];
    }

    cout << maxAreaUnderHist(hist, n) << endl;
  }
}
