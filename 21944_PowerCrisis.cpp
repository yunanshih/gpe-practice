#include <iostream>

using namespace std;

int main() {
    int N;
    while(cin >> N && N != 0) {
        for(int m=1; m < N ; m++) {
            int turnoff = 0;
            for(int i=1; i < N ; i++) {
                turnoff = (turnoff + m) % i;
            }
            if(turnoff == 11) {
                cout << m << endl;
                break;
            }
        }
    }
    return 0;
}
