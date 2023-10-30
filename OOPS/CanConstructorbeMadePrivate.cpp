

#include <iostream>

using namespace std;
class box{
  int width;  

box(int _w):width(_w){};
                            
public:
//ctor 

                        
                       

int getWidth() const{
        return width;  
}

void setter(int _val){
    width = _val;
}
    
    friend class boxFactory;
    
};

class boxFactory{
    
public:
 box getABox(int _width){
    return box(_width);    
 }
 
};




int main()
{   
    // box b(5); //in case of normal ctor it runs perfectly 
    // in case of private ctor obj cannot be created inside the main 
   
boxFactory bfact;
box b = bfact.getABox(10);  //Using boxfactory to make an object of box in case of private ctor  
cout << b.getWidth() << endl;

    return 0;
}
