#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

vector<bool> Sieve(int n) {
    vector<bool> sieve(n + 1, true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (sieve[i] == true) {
            int j = i * i;
            while (j <= n) {
                sieve[j] = false;
                j += i;
            }
        }
    }
    return sieve;
}

vector<int> SegmentedSieve(int l, int R) {
    vector<bool> sieve = Sieve(sqrt(R));
    vector<int> basePrimes;
    for (int i = 0; i < sieve.size(); i++) {
        if (sieve[i])
            basePrimes.push_back(i);
    }

    vector<int> ss(R - l + 1, 1);
    if (l == 1 || l == 0) {
        ss[0] = 0;
    }
    for (auto prime : basePrimes) {
        int first_mul = (l / prime) * prime;
        first_mul = first_mul < l ? first_mul + prime : first_mul;
        int j = max(first_mul, prime * prime);

        while (j <= R) {
            ss[j - l] = 0;
            j += prime;
        }
    }

    return ss;
}

int main() {
    int l = 110, R = 130;

    vector<int> sss = SegmentedSieve(l, R);
    for (int i = 0; i < sss.size(); i++) {
        if (sss[i]) {
            cout << i + l << " ";
        }
    }

    return 0;
}

// Wrong code 
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

vector<bool>Sieve(int n){
  //marking seive array as true 
  vector<bool>sieve(n+1, true);
  sieve[0] = sieve[1] = false;
  for(int i=2; i*i<n; i++){ //optimization part 1
    if(sieve[i] == true){

      int j = i*i; 
      while(j <= n){
        sieve[j] = false;
        j += i;
      }
    }
  }
  return sieve;
}


vector<int>SegmentedSieve(int l, int R){
  //i taking out primes and give a space marking prime
  vector<bool>sieve = Sieve(sqrt(R));
  vector<int>basePrimes;
  for(int i=0; i<sieve.size(); i++){
      if(sieve[i])
        basePrimes.push_back(i);


  }
  vector<int>ss(R-l+1, true);
  // base case if l == 1 or l == 1 
  if(l == 1 || l == 0){
     ss[0] = 0;
  }
  for(auto prime: basePrimes){
    //taking out first multiple 
    // int first_Mul = (l/prime)*prime;
    // if(first_Mul < l){
    //   first_Mul += prime;

    // }
    // //staring from first multiple j se i*i se 
    //  int j = max(first_Mul, prime*prime);
    
    
    
     int first_mul = (l / prime) * prime;
    first_mul = first_mul < l ? first_mul + prime : first_mul;
    int j = max(first_mul, prime * prime);
        
        
     while(j <= R){
      SegmentedSieve[j-l] = 0;
      j += prime;
     }

  }

  return ss;

}





int main() {
  int l = 110, R = 130;

//calling fn 
vector<bool>sss = SegmentedSieve(l, R);
for(int i=0; i<sss.size(); i++){
  if(sss[i]){
    cout << i + l << " ";
  }
}



  return 0;
}
