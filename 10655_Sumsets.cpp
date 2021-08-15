#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> set;

int main() {
    int N;
    while(cin >> N && N) {
        set.clear();
        for(int i=0; i<N; i++) {
            int e;
            cin >> e;
            set.push_back(e);
        }
        sort(set.begin(), set.end());
        bool found = false;
        for(int d=(N-1); d>0; d--){
            for(int a=0; a<d-2; a++){
                for(int b=a+1; b<d-1; b++){
                    for(int c=b+1; c<d; c++){
                        if(set[d] == set[a] + set[b] + set[c]) {
                            cout << set[d] << endl;
                            found = true;
                            break;
                        }
                    }
                }
            }
        }
        if(found == false){
            cout << "no solution" << endl;
        }
    }
}