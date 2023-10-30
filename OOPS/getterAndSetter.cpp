

            
#include <iostream>

using namespace std;
class student{

private:
string name;
char gender;
string message;

public:
int id;
int marks;



//Param constructor 
student(int id, int marks){
    this->id = id;
    this->marks = marks;
 
}

// Dtor 
~student(){
    cout << "Dtor called.. " << endl;
}
//with the help of setter method setting only those member which are private rest of the them param ctor handle  
void setter(string name, char gender, string message){
    this->name = name;
    this->gender = gender;
    this->message = message;
}
// string getter() {
//     return name, gender, message;
// }  // this will not work bcz we can't access multiple values from getter 
void getter(string &name, char &gender, string &message){
    name = this->name;
    gender = this->gender;
    message = this->message;
}

    
    
   
};
    

int main()
{
    student s1(01, 94);
    cout << s1.id << endl;
    
    s1.setter("nawaz", 'M', "Let see it will run or not");
    
    // cout << s1.getter() << endl; 
    string name;
    char gender;
    string message;
    
    s1.getter(name, gender, message);
    cout << "Name " << name << endl;
    cout << "message" << message << endl;

    return 0;
}
