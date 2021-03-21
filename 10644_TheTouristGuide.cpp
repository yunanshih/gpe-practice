#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int N, R;
    int C1, C2, P;
    int S, D, T;
    int count = 0;
    while(cin >> N >> R && N != 0 && R != 0) {
        count++;
        int capacity[N+2][N+2];
        memset(capacity, 0, sizeof(capacity)); 
        for(int i=0; i<R; i++) {
            cin >> C1 >> C2 >> P;
            capacity[C1][C2] = P;
            capacity[C2][C1] = P;
        }
        cin >> S >> D >> T;
        for(int k=1; k<=N; k++) {
            for(int i=1; i<=N; i++) {
                for(int j=1; j<=N; j++) {
                    capacity[i][j] = max(capacity[i][j], min(capacity[i][k], capacity[k][j]));
                }
            }
        }
        int left = (T % (capacity[S][D] - 1)) > 0 ? 1 : 0;
        int trips = T / (capacity[S][D] - 1) + left;
        cout << "Scenario #" << count << endl;
        cout << "Minimum Number of Trips = " << trips << endl << endl;
    }
    return 0;
}