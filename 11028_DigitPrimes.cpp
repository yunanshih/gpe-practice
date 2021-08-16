#include <iostream>
#include <cmath>

using namespace std;

int primes[1000001] = {0};

int digitsum(int n){
  int sum = 0;
  while(n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

int main() {
    primes[0] = primes[1] = 1;
    for(int i = 2; i < sqrt(1000000); i++) {
        if(!primes[i]) {
            for(int j = i + i; j < 1000000; j = j + i) {
                primes[j] = 1;
            }
        }
    }
    int cases;
    cin >> cases;
    for(int i = 0; i < cases; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        int digitprime = 0;
        for(int j = t1; j <= t2; j++) {
            if(!primes[j]) {
                if(!primes[digitsum(j)]) {
                    digitprime++;
                }
            }
        }
        cout << digitprime << endl;
    }
    return 0;
}