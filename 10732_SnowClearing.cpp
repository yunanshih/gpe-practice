#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
    int testcase;
    int hangar_x, hangar_y;
    scanf("%d\n\n", &testcase);
    for(int i=0; i<testcase; i++) {
        double distance = 0;
        scanf("%d %d\n", &hangar_x, &hangar_y);
        double x1, x2, y1, y2;
        char s[1024];
        while(gets(s) && s[0] != '\0') {
            sscanf(s, "%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
            distance += hypot(x2-x1, y2-y1);
        }
        distance /= 1000;
        double hours = distance * 2 / 20;
        int minutes = (int)round(hours * 60);
        printf("%d:%02d\n", minutes / 60, minutes % 60);
    }
    return 0;
}