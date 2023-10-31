/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
class Animal{
public:
int age;
void eat(){
    cout << "Eating " << endl;
}
    
    
    
    
};
class dog : public Animal{
    public:
    void enjoy(){
        cout << "Enjoying " << endl;
    }
};


int main()
{
    dog d;
    // d.enjoy(); //runs good 
    d.eat(); //Inherited Easily 

    return 0;
}

