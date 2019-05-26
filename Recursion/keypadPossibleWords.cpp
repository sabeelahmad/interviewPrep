#include <bits/stdc++.h>
using namespace std;

string keypadMapping(int number) {
  // This function maps a number to corresponding string keyword
  string arr[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
  return arr[number];
}

void helperAllPossibleWords(int N, string *mappings, string currentWord) {
  // Base Case : No digits remaining to be processed
  if (N == 0) {
    cout << currentWord << " ";
    return;
  }

  for(int i = 0; i < mappings[0].length(); i++) {
      string temp = currentWord + mappings[0][i];
      helperAllPossibleWords(N - 1, mappings + 1, temp);
  }
}

void getAllPossibleWords(int N, string *mappings) {
  // Call helper method
  helperAllPossibleWords(N, mappings, "");
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    // Get no of digits pressed
    int N;
    cin >> N;
    // Get digits pressed
    int D[N];
    for (int i = 0; i < N; i++) {
      cin >> D[i];
    }
    // Get corresponding string words to entered number
    string mappings[N];
    for (int i = 0; i < N; i++) {
      mappings[i] = keypadMapping(D[i]);
    }
    // Call recursive procedure to get all possible words from pressed digits
    getAllPossibleWords(N, mappings);
    cout << endl;
  }
  return 0;
}
