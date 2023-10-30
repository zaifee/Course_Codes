

#include <iostream>

using namespace std;
class base{
public:
 base(){// making a virtual function 
    cout << "Base ctor " << endl;
}

virtual ~base(){ //make dtor virtual bcz 
    cout << "Dtor called " << endl;
}

};


class derived: public base{
int *a;
public:
derived(){
     a = new int[1000];
    cout << "derived ctor " << endl;
}

~derived(){
    cout << " derived Dtor called " << endl;
}

};



int main()
{
    base *b = new base();
    delete b;

    return 0;
}
