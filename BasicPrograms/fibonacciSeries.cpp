
#include <iostream>

using namespace std;

int main()

{ 
    //ye terms pehle likhi jayegi ;;
    int firstterm = 0;
    int secondTerm = 1;
   cout << firstterm << " " << secondTerm << " ";
         
    for(int i=2; i<5; i++){
        
        
       int c = firstterm + secondTerm;
       cout << c << " ";
       
       firstterm = secondTerm;
       secondTerm = c;
       
    
    }
    
    

    return 0;
}
