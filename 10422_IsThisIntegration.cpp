#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

#define PI acos(-1.0)

int main() {
    double a;
    double x, y, z;
    while (cin >> a) {
        z = a * a - PI * a * a / 6 -  a * sqrt(3) * a / 2 / 2;
        y = a * a - PI * a * a / 4 - 2 * z;
        x = a * a - 4 * y - 4 * z;
        printf("%.3lf %.3lf %.3lf\n", x, y * 4, z * 4);
    }
    return 0;
}