#include <iostream>
#include <cmath>
using namespace std;

int digitsum(int n){
  int sum = 0;
  while(n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

int primesum(int n) {
    int temp = n;
    int sum = 0;
    while (n % 2 == 0) {
        sum += 2;
        n = n / 2; 
    } 
    for (int i = 3; i <= sqrt(n); i += 2) { 
        while (n % i == 0) {
            sum += digitsum(i);
            n = n / i;
        }
    }
    if (n > 2) {
        if(n != temp) {
            sum += digitsum(n);
        }
    }
    return sum;
}

int main() {
    int testcase;
    cin >> testcase;
    for(int i=0; i<testcase; i++) {
        int number;
        cin >> number;
        int ans = number;
        int sum = 0, prime_sum = 0;
        while(true) {
            ans++;
            sum = digitsum(ans);
            prime_sum = primesum(ans);
            if(sum == prime_sum) {
                cout << ans <<endl;
                break;
            }
        }
    }
}