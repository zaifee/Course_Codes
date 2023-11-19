#include <iostream>
using namespace std;
/*
* 
* * 
* * * 
* * * * 
* * * * * 

*/
int rows = 5;
int main() {
  for(int row=0; row<rows; row++){
    for(int col=0; col<row+1; col++){  //yaha galti kar rha tha
       cout << "*" << " ";
    }
    cout << endl;
  }
  return 0;
}
