#include <bits/stdc++.h>
using namespace std;

void helperPermutation(string S, string currentPerm);
void permutation(string S);

int main() {
  int t;
  cin >> t;
  while(t--) {
    string S;
    cin >> S;
    permutation(S);
    cout << endl;
  }
  return 0;
}

void helperPermutation(string S, string currentPerm) {
    // Base case, if length of String is 1
    if (S.length() == 1) {
        cout << currentPerm+S << " ";
        return;
    }

    for(int i = 0; i < S.length(); i++) {
        // Swap
        char temp = S[0];
        S[0] = S[i];
        S[i] = temp;
        string temp2 = currentPerm;
        temp2 += S[0];
        // Recursively call on rest of the string
        helperPermutation(S.substr(1), temp2);
    }
}

void permutation(string S)
{
    // Sort string
    sort(S.begin(), S.end());
    helperPermutation(S, "");
}
