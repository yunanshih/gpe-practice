#include <iostream>
using namespace std;

// for (i = 1 to n) begin
//   LIS[i] = 1;
//   for (j = i-1 to 1) begin
//     if (LIS[j]+1 > LIS[i] && ...) begin
//       ...
//     end
//   end
// end

int main() {
    int n;
    while (cin >> n) {
        int array[n];
        int LIS[n];
        for(int i=1; i<=n; i++) {
            cin >> array[i];
        }
        for(int i=1; i<=n; i++) {
            LIS[i] = 1;
            for(int j=i-1; j>=1; j--) {
                if(LIS[j]+1 > LIS[i] && array[i] > array[j]) {
                    LIS[i] = LIS[j]+1;
                }
            }
        }
        int length = 0;
        for(int i=1; i<=n; i++) {
            length = max(length, LIS[i]);
        }
        cout << length << endl;
    }
    return 0;
}