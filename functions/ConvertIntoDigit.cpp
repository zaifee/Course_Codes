#include <iostream>
using namespace std;
int convertDigits(int numberOfDigits){
  int num = 0;
  for(int i=0; i<numberOfDigits; ++i){
    cout << "Enter Digits " << endl;
    int digit;
    cin >> digit;
    num = num * 10 + digit;
    cout << "Number of Digits created so far " << num << endl;
  }
  return num;
}
int main() {
  
  int numberOfDigits;
  cin >> numberOfDigits;
  int ans = convertDigits(numberOfDigits);
  cout << "Number created by digits " <<ans <<  endl;


  return 0;
}
