#include <iostream>
using namespace std;

char map[101][101];

int findOil(int i, int j) {
    map[i][j] = 'X';
    if(map[i-1][j-1] == '@')
        findOil(i-1, j-1);
    
    if(map[i-1][j] == '@')
        findOil(i-1, j);
    
    if(map[i-1][j+1] == '@')
        findOil(i-1, j+1);

    if(map[i][j-1] == '@')
        findOil(i, j-1);

    if(map[i][j+1] == '@')
        findOil(i, j+1);

    if(map[i+1][j-1] == '@')
        findOil(i+1, j-1);

    if(map[i+1][j] == '@')
        findOil(i+1, j);

    if(map[i+1][j+1] == '@')
        findOil(i+1, j+1);
    return 0;
}

int main() {
    int m, n;
    int count = 0;
    while(cin >> m >> n && m != 0 && n != 0) {
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
                    count++;
                }
            }    
        }
        cout << count << endl;
    }
    return 0;
}