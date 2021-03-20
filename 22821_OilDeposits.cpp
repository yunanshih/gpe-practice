#include <iostream>
using namespace std;

#define MAXSIZE 100

char map[MAXSIZE+1][MAXSIZE+1];
int count = 0;

int findOil(int i, int j) {
    bool found = false;
    map[i][j] = 'X';
    count++;

    if(map[i-1][j-1] == 'X')
        found = true;
    if(map[i-1][j-1] == '@')
        map[i-1][j-1] = 'X';
    
    if(map[i-1][j] == 'X')
        found = true;
    if(map[i-1][j] == '@')
        map[i-1][j] = 'X';
    
    if(map[i-1][j+1] == 'X')
        found = true;
    if(map[i-1][j+1] == '@')
        map[i-1][j+1] = 'X';

    if(map[i][j-1] == 'X')
        found = true;
    if(map[i][j-1] == '@')
        map[i][j-1] = 'X';

    if(map[i][j+1] == 'X')
        found = true;
    if(map[i][j+1] == '@')
        map[i][j+1] = 'X';

    if(map[i+1][j-1] == 'X')
        found = true;
    if(map[i+1][j-1] == '@')
        map[i+1][j-1] = 'X';

    if(map[i+1][j] == 'X')
        found = true;
    if(map[i+1][j] == '@')
        map[i+1][j] = 'X';

    if(map[i+1][j+1] == 'X')
        found = true;
    if(map[i+1][j+1] == '@')
        map[i+1][j+1] = 'X';

    if(found)
        count--;
    return 0;
}

int main() {
    int m, n;
    while(cin >> m >> n) {
        if(m == 0 && n == 0)
            break;
        for(int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> map[i][j];
            }    
        }
        count = 0;
        for(int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(map[i][j] == '@') {
                    findOil(i, j);
                }
            }    
        }
        cout << count << endl;
    }
    return 0;
}