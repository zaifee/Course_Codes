
#include <iostream>
// Shallow Copy vs Deep copy 
using namespace std;
class abc{
public:
int x,*y;

abc(int _x, int _y):x(_x),y(new int(_y)){}

void print() const{
    printf("X:%d\n PTR Y:%p\n Content of Y(*y): %d\n\n", x, y, *y);
}
//Making a deep copy 
// abc(const abc& obj){
//     x = obj.x;
//     y = new int(*obj.y); //it will make a new copy for y now y points to anoter location 
// }


//desturctor 
~abc(){
    delete y;
}
    
    
};



int main()
{
    // abc a{1,2};
    // a.print();
    
    // abc b = a;
   
    // b.print();
    
    // //changing value of y;
    // cout << "Printing the value of b after changing " << endl;
    // *b.y = 20;
    
    // b.print();
    
    // cout << "Printing the value of a after changing " << endl;
    // a.print();
    
    // -- don't use shallow copy when using pointers use deep copy 
    
    abc *a = new abc(1,2);
    abc b = *a;
    delete a;
    b.print();
    
    
    

    return 0;
}
