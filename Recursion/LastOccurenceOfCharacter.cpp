
#include <iostream>

using namespace std;
//Last Occurence of Character -- left to right

void lastOccurenceOfStringLTR(string&s, char x, int index, int&ans){
    
    //base case 
    if(index >= s.size()) return;
    
    //processing 
    if(s[index] == x){
        ans = index;
    }
    
    //recursive call 
    lastOccurenceOfStringLTR(s, x, index+1, ans);
    
    
}

//right to left 
void lastOccurenceOfStringRTL(string&s, char x, int index, int&ans){
    
    //base case 
    if(index < 0) return;
    
    //processing 
    if(s[index] == x){
        ans = index;  //if first character is found right to left then simply return 
        return;
    }
    
    //recursive call 
    lastOccurenceOfStringRTL(s, x, index-1, ans); //start from i-1;
    
    
}

int main()
{
    string str;
    cout << "Enter the String for which You want to find the last Character " << endl;
    cin>>str;
    
    char x;
    cout << "Enter the Character " << endl;
    cin >> x;
    int index = 0;
    int ans = -1;
    // lastOccurenceOfStringLTR(str, x, index, ans);
    lastOccurenceOfStringRTL(str, x, str.size()-1, ans);
    
    cout << ans << endl;

    return 0;
}
