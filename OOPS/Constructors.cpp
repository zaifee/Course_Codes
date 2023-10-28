
#include <iostream>
using namespace std;

class Student{
private:
string gf;
string bf;
void chatting(){
    cout << "Chatting with gf " << endl;
}
public:
int id;
string name;
int age;
string gender;

//default constructor 
 Student(){
     cout << "Defalult Ctor called " << endl;
 }
 
 
 // ------- Parameterized Constructor -----------
//  Student(int _id, string _name, int _age, string _gender, string _gf){
     
//      name = _name;
//      id = _id;
//      age = _age;
//      gender = _gender;
//      gf = _gf;
//      cout << "Parameterized ctor called " << endl;
     
    
//  }
 
 
 
  Student(int _id, string _name, int _age, string _gender, string _bf){
     
    
     id = _id;
      name = _name;
     age = _age;
     gender = _gender;
     bf = _bf;
     cout << "Parameterized ctor called " << endl;
    
    
 }
 
 

};



int main()
{
  
// Student Creation of s1; 
Student s1(001, "Love", 21, "female", "Indumati");
cout << s1.name << endl;
  
  
// Student Creation of s2;
Student s2(002, "Zaifee", 23, "Male", "Desi Girl");
cout << s2.name << endl;







    return 0;
}
