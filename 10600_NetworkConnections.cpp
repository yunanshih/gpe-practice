#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
  int cases;
  cin >> cases;
  for(int i=0; i<cases; i++) {
      int computers;
    cin >> computers;
      vector<int> connected(computers + 1);
      for(int i = 1 ; i <= computers ; i++){
        connected[i] = i;
      }


      cin.ignore();
            string input;
            int right = 0, wrong = 0;
      while(getline(cin, input) && input[0]) {
        stringstream ss(input);
        char type;
        int computerI, computerJ;
        ss >> type >> computerI >> computerJ;
        cout << type <<computerI << computerJ << endl;
        if(type == 'c') { 
          int groupI = connected[computerI], groupJ = connected[computerJ];
          for(int i = 1 ; i <= computers ; i++){
            if(connected[i] == groupI || connected[i] == groupJ) {
                connected[i] = min(groupI, groupJ);
            }
          }
        }
        else if(type == 'q') {
          if(connected[computerI] != connected[computerJ]){
            wrong++;
          }
          else {
            right++;
          }
        }
      }
      cout << right << ',' << wrong << endl;
    }
  return 0;
}

// #include <iostream>
// #include <sstream>
// #include <cstdio>
// #include <vector>
// using namespace std;

// int main(){
//   int testcase;
//   while( scanf("%d", &testcase) != EOF ){

//     for( int caseNumber = 0 ; caseNumber < testcase ; ++caseNumber ){
//       if( caseNumber >= 1 ){
//         printf("\n");
//       }

//       int numberOfComputers;
//       scanf("%d", &numberOfComputers);

//       vector<int> connected(numberOfComputers+1);
//       for( int i = 1 ; i <= numberOfComputers ; ++i ){
//         connected[i] = i;
//       }


//       int rightAnswer = 0, wrongAnswer = 0;
//       string input;
//       cin.ignore();
//       while( getline(cin, input) && input != "" ){

//         stringstream ss(input);
//         char type;
//         int computerI, computerJ;
//         ss >> type >> computerI >> computerJ;

//         if( type == 'c' ){ 
//           int groupI = connected[computerI], groupJ = connected[computerJ];
//           for( int i = 1 ; i <= numberOfComputers ; ++i ){
//             if( connected[i] == groupI || connected[i] == groupJ ){
//               connected[i] = min(groupI, groupJ);
//             }
//           }
//         }
//         else if( type == 'q' ){
//           if( connected[computerI] != connected[computerJ] ){
//             ++wrongAnswer;
//           }
//           else{
//             ++rightAnswer;
//           }
//         }
//       }

//       printf("%d,%d\n", rightAnswer, wrongAnswer);
//     }
//   }

//   return 0;
// }