
#include <iostream>
 
using namespace std;
 
int main() {
	int n, m, turnoff;
	while (cin >> n && n) {
		for (int m = 1 ; m < n; m++) {
			turnoff = 0;
			for (int i = 1; i < n; i++) {
                turnoff = (turnoff + m) % i;
            }
            if (turnoff == 11) {
                cout << m << endl;
                break;
            }
		}
	}
	return 0;
}