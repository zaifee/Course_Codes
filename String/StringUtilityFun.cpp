#include<iostream>
using namespace std;
int main(){
    
    string name;
    // getline(cin, name);
    
    // cout << "Length of String is : " << name.length() << endl;
    // cout << "Is String empty : " << name.empty() << endl;
    // cout << "Second letter of Nawaz is : " << name.at(1) << endl;
    // cout << "Front Character of Nawaz is : " << name.front() << endl;
    // cout << "last Character of Nawaz is : " << name.back() << endl;
    
    // string str1 = "Mohd";
    // string str2 = "Nawaz";
    // cout << "Before Appending the String " << endl;
    // cout << str1 << endl;
    // cout << str2 << endl;
    // str1.append(str2);
    // cout << "After Appending the String " << endl;
    // cout << str1 << endl;
    // cout << str2 << endl;
    
    //string erase
    
    // string str = "This is Erase Example let see how this function workds ";
    // // str.erase(str.begin()+7, str.end()+10);
    // str.erase(7,11);
    // cout << "Now your String looks like: " << endl;
    // cout << str;
    
    /*string insert
    string str = "Nawaz Zaifre";
    string str2 = "the ";
    cout <<  "Before Inserting the String looks like " << str << " " << str2 << endl;
    str.insert(6, str2);
    cout << "Your Sring now looks like: " << str << endl;
    */
    
    /*push and pop back
    string name1;
    cin >> name1;
     
    name.push_back('z');
    cout << "Name After Pushing: " << endl;
    cout << name << endl;
    
    name1.pop_back();
    cout <<" Your String After Pop would looks like : " << endl;
    cout << name1 << endl;
    */
    
    //finding the String 
    string str = "yaar tera supar Star or desi kalakar ";
    string str2 = "me";
    
    if(str.find(str2) == string::npos){
        cout << " Hurrah ! Word Found " << endl;
    }else{
        cout << " This Word is not exist in the String " << endl;
    }
   
    
      //finding the String 
    string str = "yaar tera supar Star or desi kalakar ";
    string str2 = "me hu re raja";
    
    if(str == str2){
        cout << " Hurrah ! Word Found " << endl;
    }else{
        cout << " This Word is not exist in the String " << endl;
    }
   
   //string sub part
   string des = "Hello ji ! kya haal chaal ";
   cout << des.substr(6,8) << endl;
    
    return 0;
}
