#include <bits/stdc++.h>
#define ll long long int
using namespace std;
bool sieve[10000001];
// we need to print sum of all primes that can be represented as sum of two primes
// a prime no can be represented as sum of two primes if and only if n - 2 is also prime
// we generate all primes from 1 to N using sieve and then check if n - 2 is prime and get the ans
int main() {
  memset(sieve, true, sizeof(sieve));
  for(ll p = 2; p*p <= 10000000; p++) {
    // if p is prime, mark all its multiples as not prime
    if(sieve[p] == true) {
      // mark all multiples from p*p to n as false
      for(ll i = p*p; i <= 10000000; i += p) {
        sieve[i] = false;
      }
    }
  }
  // make array of superprimes till max possible N acc to question to save time
  vector<ll> superPrimes;
  for(ll p = 5; p <= 10000000; p++) {
    if(sieve[p] && sieve[p-2]) {
      superPrimes.push_back(p);
    }
  }
  int t;
  cin >> t;
  while(t--) {
    ll n;
    cin >> n;
    // now we just need to see in the vector of superprimes the upper bound of n
    // since the greatest number than n will be upper bound, we can subtract that from begining of vector
    // to get no of superPrimes <= n
    cout << upper_bound(superPrimes.begin(), superPrimes.end(), n) - superPrimes.begin() << endl;
  }
}
