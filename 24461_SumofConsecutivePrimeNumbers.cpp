#include <iostream>
#include <vector>
using namespace std;

vector <int> prime;

bool isprime(int n) {
    for(int i = 2; i < n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    for(int i = 2; i < 10000; i++) {
        if(isprime(i)) {
            prime.push_back(i);
        }
    }
    int n;
    while(cin >> n && n != 0) {
        int count = 0;
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum = sum + prime[j];
                if(sum == n) {
                    count++;
                    break;
                }
                if(sum > n)
                    break;
            }
        }
        cout << count << endl;
    }
    return 0;
}