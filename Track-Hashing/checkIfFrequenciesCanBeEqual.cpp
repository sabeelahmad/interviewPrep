#include <bits/stdc++.h>
using namespace std;

bool allFreqsSame(int* freq) {
    int f;
    for(int i = 0; i < 26; i++) {
        if(freq[i] > 0) {
            f = freq[i];
            break;
        }
    }

    for(int i = 0; i < 26; i++) {
        if(freq[i] > 0 && freq[i] != f) {
            return false;
        }
    }
    return true;
}


bool canFreqsBeEqual(string s1) {
    int n = s1.size();
    int freq[26] = {0};
    for(int i = 0; i < n; i++) {
        freq[s1[i] - 'a']++;
    }

    // if all freqs are same return true
    if(allFreqsSame(freq)) {
        return true;
    }

    // if all not same, for all characters a to z decrease freq by 1, simulating removal
    // if after that freqs become same ans is true, if for no char it becomes same ans is false
    for(char c = 'a'; c <= 'z'; c++) {
        if(freq[c - 'a'] > 0) {
            freq[c - 'a']--;
            if(allFreqsSame(freq)) {
                return true;
            }
            freq[c - 'a']++;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s1;
        cin >> s1;
        cout << canFreqsBeEqual(s1) << endl;
    }
}