#include <iostream>
#include <string.h>
using namespace std;
void convertToUpperCase(char ch[], int n){
    int i=0;
    while(ch[i] != '\0'){
     char currCurr = ch[i];
     if(ch[i] >= 'a' && ch[i] <= 'z'){
         ch[i] = currCurr-'a'+'A';
         
     }
     i++;
    }
}
void convertToLowerCase(char ch[], int n){
    int i=0;
    while(ch[i] != '\0'){
     char currCurr = ch[i];
     if(ch[i] >= 'A' && ch[i] <= 'Z'){
         ch[i] = currCurr-'A'+'a';
         
     }
     i++;
    }
}

int main()
{
    char ch[100];
    cin.getline(ch, 100);
  
   cout << "Before Converting to Uppercase "<< ch << endl;
   convertToUpperCase(ch, 100);
   cout << "After Converting to Uppercase "<< ch << endl;
   
   cout << "Converting to lower Case " << endl;
   convertToLowerCase(ch, 100);
   cout << "Your lower Case is on the way... " << endl;
   cout << ch;
    
   

    return 0;
}
