
#include <iostream>
#include <string.h>
using namespace std;
void reverse(string &str, int s, int e){
    //base case 
    if(s >= e) return;
    
    //processing 
    swap(str[s], str[e]);
    
    
    //recursive call 
    reverse(str, s+1, e-1);
}
int main()
{
    string str = "hello";
    int s= 0;
    int e = str.size()-1;
    
    reverse(str,s, e);
    
    cout << str << endl;
    
    return 0;
}
