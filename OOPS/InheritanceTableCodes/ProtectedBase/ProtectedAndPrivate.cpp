#include<iostream>

using namespace std;
class Animal{
protected:
int age;
void eat(){
    cout << "Eating " << endl;
}
    
    
    
    
};
class dog : private Animal{
    public:
    void enjoy(){
        cout << "Enjoying " << endl;
    }
};


int main()
{
    dog d;
    d.enjoy(); //runs good 
    d.eat(); //can't inherited 

    return 0;
}
