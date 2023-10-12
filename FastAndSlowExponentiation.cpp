#include <iostream>
using namespace std;
int fastExponentiation(int a, int b){
   int ans = 1;
   while(b > 0){
    if(b & 1){
      ans *= a;
    }
    //if a is even 
    a = a * a;
    b = b>>1; //right shift 
   }
   return ans;
}

// int slowExponentiation(int a, int b){
//   int ans = 1;
//   for(int i=0; i<b; i++){
//      ans *= a;
//   }
//   return ans;
// }
int main() {
  int a = 3;
  int b = 3;
  // cout << slowExponentiation(a, b) << endl;
 cout << fastExponentiation(a, b) << endl;
  return 0;
}
