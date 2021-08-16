#include <iostream>
#include <cstdio>
using namespace std;

// 100.00 50.00 20.00 10.00 5.00 2.00 1.00 0.50 0.20 0.10 0.05
int coins[11] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};

int main() {
 int dollar = 0, cent = 0;
   while(scanf("%d.%d", &dollar, &cent) != EOF && !(dollar == 0 && cent == 0)) {
    long long int dp[30005] = {1};
    dp[0] = 1;
    for(int i = 0; i<11; i++) {
        for(int j = coins[i]; j<=30000; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }
    printf("%3d.%02d%17lld\n", dollar, cent, dp[dollar*100 + cent]);
   }
  return 0;
}