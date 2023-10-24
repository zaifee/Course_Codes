

#include <iostream>

using namespace std;

int main()
 {
//     int *a = new int;
//     *a = 2;
//     cout << *a << endl;
//     // delete a; 
    
//     int b = 5;
//     a = &b;
//     cout << *a << endl;  

// 2. const data, but  pointer
// const int *a = new int(5); //const int data 
// int const *a = new int(5); same as line no 25
// *a = 20;

// cout << *a << endl; 
// int b = 10;
// a = &b;
// cout << *a << endl;


// 3. const pointer, but change data 
int *const a = new int(10);
cout << *a << endl;
*a = 43;
cout << *a << endl;

int b = 50;
a = &b; //nhi chlega bcz of const pointer 
cout << *a << endl;




    
    
    

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

