/******************************************************************************

                              Online C++ Compiler.
              Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <math.h>
using namespace std;
void convertIntoDigits(int &n){
    int ans = 0;
    int digit;
    
    while(n > 0){
        int digit = n % 10;
        ans = (ans * 10) + digit;
         
        n = n/10;
     
        
    }
    cout << ans;
}
int main()
{
    int n = 345;
    convertIntoDigits(n);

    return 0;
}
