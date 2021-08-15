#include <iostream>
#include <cstring>

using namespace std;

char map[21][21];
bool visited[21][21];

int findLanguage(int i, int j) {
    visited[i][j] = true;
    if(map[i-1][j] == map[i][j] && !visited[i-1][j]) {
        findLanguage(i-1, j);
    }
    if(map[i+1][j] == map[i][j] && !visited[i+1][j]) {
        findLanguage(i+1, j);
    }
    if(map[i][j-1] == map[i][j] && !visited[i][j-1]) {
        findLanguage(i, j-1);
    }
    if(map[i][j+1] == map[i][j] && !visited[i][j+1]) {
        findLanguage(i, j+1);
    }
}

int main () {
    int N, H, W;
    int maxarea;
    cin >> N;
    for(int count = 1; count <= N; count++) {
        cin >> H >> W;
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                cin >> map[i][j];
                visited[i][j] = false;
            }
        }
        int language[27] = {0};
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                if(!visited[i][j]) {
                    language[map[i][j] - 'a']++;
                    findLanguage(i, j);
                    maxarea = max(language[map[i][j] - 'a'], maxarea);
                }
            }
        }
        cout << "World #" << count << endl;
        for(int i = maxarea; i > 0; i--) {
            for(int j = 0; j < 26; j++) {
                if(language[j] == i) {
                    cout << char('a' + j)  << ": " << language[j] << endl;
                }
            }
        }
    }
    return 0;
}