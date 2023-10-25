#include <iostream>

using namespace std;
class abc{
//  mutable int x; 
 int x;
  int *y;
 const int z;
public:
abc(){
    x = 0;
    y = new int(0);
    z = 32;
}
// abc(int _x, int _y, int _z=0){
//     x = _x;
//     y = new int(_y);
//     z = _z;
// }
//Intialization list 
abc(int _x, int _y, int _z):x(_x), y(new int(_y)), z(_z){};

int getx() const{
    //  x = 20; // how to change this variable with presence of const then marked x as mutable
    return x;
}

void setX(int _val){
    x = _val;
}


int gety() const{
    return *y;
}

void sety(int _val){
    *y = _val;
}

int getz() const{
    return z;
}

  
    
};


void printAbc(const abc &a){ //print abc call only variable that is marked const 
    cout << a.getx() << " " << a.gety() << " " << a.getz() << endl;
}





int main()
{
    
    abc a(1,2, 5);  //we declared z but did not passed we passed in the function which is called default argument
    
    printAbc(a);
    
    
    
     abc s1;
     
    
    // cout << s1.getx() <<endl;
    // cout << s1.gety() << endl;
    
    
    

    return 0;
}
