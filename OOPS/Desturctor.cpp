

#include <iostream>

using namespace std;
class student{
 public:
 int *id;
 int age;
 string name;
 
 //default ctor 
 student(){
     cout << "Default Ctor called " << endl;
 }
 student(int id, int age, string name){
     cout << "Parameterized ctor called " << endl;
     this->id = new int(id); //dynamically me id andar aaye gi ye likhna bhul gaya tha 
     this->age = age;
     this->name = name;
 }
 
 
 ~student(){
     cout << "Default Dtor called " << endl;
     delete id;
 }
    

    
};





int main()
{
   student s1(22, 23, "Nawaz");
//   s1.id = 01;
   s1.age = 22; 
   s1.name = "Nawaz"; //if you don't want to mention explicityly the details of member variable we can use ctor 
//   cout << s1.id << endl;
//   cout << s1.name << endl;  this will not run bcz class has no member name 
cout << s1.name << endl;
student s2;
cout << s2.age << endl;
// student s3;   


student *s3 = new student(001, 20, "faraz");
cout << s3->name << endl;
delete s3;

    return 0;
}
