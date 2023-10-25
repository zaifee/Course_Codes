#include <iostream>

using namespace std;




class abc{
   public:
static  int x,y;

void printNumber() const{ //this pointer is a pointer belong to the obj that for which it is created 
    cout << this->x << " " << this->y << endl;
    
} 

// as member as declared as static so it is accessible to all variable 
abc :: x; //x is accessible to all instaces of class 
abc :: y;


    
    
    
};

int main()
{
   abc a = {1,2};
   a.printNumber();
   
   
   abc obj2 = {3,4};
   obj2.printNumber();



    return 0;
}
