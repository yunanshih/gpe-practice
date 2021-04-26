#include <iostream>
#include <algorithm>
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
        for(int i=0; i<n; i++) {
            cin >> array[i];
            LIS[i] = 1;
        }
        int count = 1;
        for(int i=1; i<n; i++) {
            for(int j=i-1; j>=0; j--) {
                if (array[i] > array[j]) {
                    if(LIS[i] == LIS[j]) {
                        LIS[i]++;
                    } else if (LIS[i] < LIS[j]) {
                        LIS[i] += LIS[j];
                    }
                    if (LIS[i] > count){
                        count = LIS[i];
                    }
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}