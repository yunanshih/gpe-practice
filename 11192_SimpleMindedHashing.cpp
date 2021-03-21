#include <iostream>
using namespace std;

int main() {
    int L, S;
    int dp[27][27][352];
    int count = 0;
    while(cin >> L >> S && L != 0 && S != 0) {
        count++;
        dp[0][0][0] = 1;
        for(int i=1; i<=26; i++) {
            for(int j=0; j<=i; j++) {
                for (int k=0; k<=351; k++) {
                    dp[i][j][k] = dp[i-1][j][k];
                    if(j > 0 && k >= i) {
                        dp[i][j][k] += dp[i-1][j-1][k-i];
                    }
                }   
            }
        }
        if(L <= 26 && S <= 351) {
            cout << "Case " << count << ": " << dp[26][L][S] << endl;
        } else {
            cout << "Case " << count << ": " << 0 << endl;
        }
    }
    return 0;
}