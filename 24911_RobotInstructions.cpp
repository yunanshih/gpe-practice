#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main() {
    int n;
    int lines;
    vector<int> insturctions;
    vector<int> positions;
    string insturction;
    string dump;
    int index;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> lines;
        int x = 0;
        insturctions.clear();
        for (int j=0; j < lines; j++) {
            cin >> insturction;
            if(insturction == "LEFT") {
                x--;
                insturctions.push_back(-1);
            } else if (insturction == "RIGHT") {
                x++;
                insturctions.push_back(1);
            } else {
                cin >> dump;
                cin >> index;
                x += insturctions[index-1];
                insturctions.push_back(insturctions[index-1]);
            }
        }
        positions.push_back(x);
    }
    for(int i=0; i<n; i++) {
        cout << positions[i] << endl;
    }
    return 0;
}