#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    double h, m;
    cin >> h >> m;

    // we take h = 12 and m = 0 as reference
    // minute hand does 360deg in 60 minutes, that is 6 degrees per minute
    // hour hand does 360 deg in 720 minutes (12 hrs) that is 0.5 degree per minute

    if(h == 12) h = 0;
    if(m == 60) m = 0;

    double h_angle = 0.5 * (h*60 + m);
    double m_angle = 6*m;
    //cout << h_angle << " " << m_angle << endl;
    double angle = abs(h_angle - m_angle);
    cout << int(min(angle, 360 - angle)) << endl;
  }
}
