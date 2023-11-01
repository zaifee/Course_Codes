/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

//to check that it is a ArmStrong Number hai.

#include <iostream>

using namespace std;

int main()
{
    int n; // indicating a number for which we have to check;
    int r;  //to find individual digit cube  
   int sum=0; //to store the sum of all digits cube of a no
    int temp; //for storing the actual value of n 
  
  cin >> n;
  temp = n;
  while(n){
      
      r = n % 10;
      sum += (r*r*r);
      n /= 10;
      
      
  
  }
  if(temp == sum){
      cout << "armstrong number hai.." << endl;
  }else{
      cout << "Not a Armstrong Number: " << endl;
  }
  
  
 
    return 0;
}
