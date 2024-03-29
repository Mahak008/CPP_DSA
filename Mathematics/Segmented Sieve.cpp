#include <bits/stdc++.h>
using namespace std;

int N = 1000000;
vector <bool> sieve(N + 1, true);

void createSieve() {
  for(int i = 2; i <= N;i++) {
    sieve [i] = true;
  }

  for(int i = 2; i*i <= N;i++) {
    if (sieve [i] == true) {
      for(int j = i*i; j <= N; j+=i) {
        sieve [j] = false;
      }
    }
  }
}

vector<int> generatePrimes (int N) {
  vector <int> ds;
  for(int i = 2; i <= N; i++) {
    if(sieve[i] == true) {
      ds.push_back(i);
    }
  }
  return ds;
}

int main() {
  createSieve();
  int l = 110 , r = 130 ;
  
  // step 1: Generate all primes till sqrt(r)
  vector <int> primes = generatePrimes(sqrt(r));

  // step2 : Create a dummy array of size (R - L + 1) as 1
  int dummy [r - 1 + 1];
  for(int i = 0; i < (r-l+1); i++) {
    dummy [i] = 1;
  }

  // step 3 : For all prime number marks its multiples as false
  for(auto pr: primes) {
    int firstMultiple = (l/pr) * pr;
    if(firstMultiple < 1) { 
      firstMultiple += pr;
    }
    for(int j = max(firstMultiple, pr*pr); j <= r; j += pr) {
      dummy [j-l] = 0;
    }
  }

  // step 4: get all the primes
  for(int i = l; i <= r; i++) {
    if(dummy[i-l] == 1) {  
      cout << i << " ";
    }
  }
  cout << endl;
  return 0;
}
