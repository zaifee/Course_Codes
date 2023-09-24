#include<iostream>
#include <string.h>

using namespace std;

void reverseString(char ch[], int size){
    int i=0;
    int j = size-1;
    while(i <= j){
        int temp = ch[i];
        ch[i] = ch[j];
        ch[j] = temp; //swapping done now inc or dec the pointer
        
        i++;
        j--;
    }
}

int main(){
    char ch[100];
    cin.getline(ch, 100);
    
    cout << "Before Reversal " << ch << endl;
    int len = strlen(ch);  //passing only len which contain some character
    reverseString(ch, len);
    
    cout << "After Reverse the Array would look like this:  "  << endl;
    cout << ch;
    

    
    return 0;
}
