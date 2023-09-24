/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int findLength(char ch[], int size){
    int len = 0;
    int i = 0;
    while(ch[i] != '\0'){
        len++;
        i++;
    }
    return len;
}
int main()
{ 
    char ch[100];
    // cin >> ch;
    cin.getline(ch, 99);
    // int ans = findLength(ch, 100);
    
    cout << "Your lenght of char Array is : " << strlen(ch) << endl;
     
    return 0;
}
