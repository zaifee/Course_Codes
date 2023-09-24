
#include <iostream>
#include <string.h>
using namespace std;
bool palindromeCheck(char ch[], int n){
    int i = 0;
    int j = n-1;
    while(i <= j){
        if(ch[i] == ch[j]){
            i++;
            j--;
        }else{
            
            return false;
        }
       
    }
     //if reached hre then the given String is Palindrome
        return true;
}

int main()
{
   char ch[100];
   cin.getline(ch, 100);
   int len = strlen(ch);
   
 bool isPalindrome = palindromeCheck(ch, len);
 if(isPalindrome){
     cout << "Your String is Palindrome " << endl;
 }else{
     cout << "Not palindrome " << endl;
 }

    return 0;
}
