

#include <iostream>

using namespace std;

int main()
{
    
//Const data but variable Pointers data 
   const int * a = new int(10); //is field me kya data dena hai wo hai 
//   cout << *a << endl;
//   cout << *a+1 << endl;
   int b = 101;  //a husband b wife here  - #Const data but Var Pointers 
   a = &b;
//   cout << *a << endl; //Here data can be change through pointers



// 2. Case -- VAr data but Const pointer

int *const d = new int(32);
*d = 20;
// cout << *d << endl;
int gf = 10;
d = &gf;
cout << *d << endl;





   
// 3. case both Const   
   const int * const z = new int(5);
//   cout << *z << endl;
//   int c = 200;
//   z = &c;
//   cout << *z << endl; //let see husband win or wife win -- husband win here no data can be changed 

    return 0;
}





2. ---------- Second Part -------------

#include <iostream>

using namespace std;
class abc{
  int x;
  int *y;
public:
abc(){
    x = 0;
    y = new int(0);
}

int getx() const{
    
    return x;
}

void setX(int _val){
    x = _val;
}


int gety(){
    return *y;
}

void sety(int _val){
    *y = _val;
}



    
    
    
};


int main2(){
    
   
  return 0;  
}

int main()
{
    
     abc s1;
    
    cout << s1.getx() <<endl;
    cout << s1.gety() << endl;
    
    
    

    return 0;
}

