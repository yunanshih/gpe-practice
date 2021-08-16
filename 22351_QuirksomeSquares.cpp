#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int digits = 0;
    while(cin >> digits) {
        if(digits == 2) {
            for(int i = 0; i < 9; i++) {
                for(int j = 0; j < 9; j++) {
                    if((i+j) * (i+j) == i*10+j) {
                        printf("%02d\n", i*10+j);
                    }
                }
            }
        }
        if(digits == 4) {
            for(int i = 0; i < 99; i++) {
                for(int j = 0; j < 99; j++) {
                    if((i+j) * (i+j) == i*100+j) {
                        printf("%04d\n", i*100+j);
                    }
                }
            }
        }
        if(digits == 6) {
            for(int i = 0; i < 999; i++) {
                for(int j = 0; j < 999; j++) {
                    if((i+j) * (i+j) == i*1000+j) {
                        printf("%06d\n", i*1000+j);
                    }
                }
            }
        }
        if(digits == 8) {
            for(int i = 0; i < 9999; i++) {
                for(int j = 0; j < 9999; j++) {
                    if((i+j) * (i+j) == i*10000+j) {
                        printf("%08d\n", i*10000+j);
                    }
                }
            }
        }
    }
    return 0;
}