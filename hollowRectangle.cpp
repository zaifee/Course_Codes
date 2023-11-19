#include <iostream>
using namespace std;
int rows = 10;
int cols = 7;

int main() {
 for(int i=0; i<rows; i++){
  for(int j=0; j<cols; j++){
    if(i == 0 || i == rows-1){
      cout << "*";  //yaha galti ki thi star ke bad space de diya tha
    }
    else{
      if(j == 0 || j == cols-1){
        cout << "*";
      }else{
        cout << " ";
      }
    }
  }
  cout << endl;
 }
  return 0;
}


























#include <iostream>
using namespace std;
*****
*   *
*   *
*   *
*****

int main() {
 for(int i=0; i<5; i++){
  for(int j=0; j<5; j++){
    if(i == 0 || i == 4){
      cout << "*";  //yaha galti ki thi star ke bad space de diya tha
    }
    else{
      if(j == 0 || j == 4){
        cout << "*";
      }else{
        cout << " ";
      }
    }
  }
  cout << endl;
 }
  return 0;
}
