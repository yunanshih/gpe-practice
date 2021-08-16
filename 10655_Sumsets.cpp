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
        for(int d=N-1; d>0; d--){
            for(int a=0; a<N-1; a++){
                if(set[a] == set[d]) continue;
                for(int b=a+1; b<N-1; b++){
                    if(set[b] == set[d] || set[b] == set[a]) continue;
                    for(int c=b+1; c<N-1; c++){
                        if(set[c] == set[d] || set[c] == set[b] || set[c] == set[a]) continue;
                        if(set[d] == set[a] + set[b] + set[c]) {
                            cout << set[d] << endl;
                            found = true;
                            break;
                        }
                    }
                    if(found) break;
                }
                if(found) break;
            }
            if(found) break;
        }
        if(!found){
            cout << "no solution" << endl;
        }
    }
    return 0;
}