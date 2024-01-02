/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    cout << "Enter the Number of rows for which you want to print Inverted pyramid: " << endl;
    int n;
    cin >> n;
    // int count = 1;
    for(int row=1; row<=n; row++){
       for(int col=1; col<=n-row; col++){
           cout << col << " ";
        //   count++;
       }
       cout << endl;
    }

    return 0;
}
