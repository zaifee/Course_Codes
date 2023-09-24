
#include <iostream>
using namespace std;
void replacingChar(char ch[], int n){
  int i = 0;
   while(ch[i] != '\0'){
     
      
      if(ch[i] == '@'){
          //insert space
          ch[i] = ' ';
      }
      i++;
       
   }
}

int main()
{
   char ch[100];
   cin.getline(ch, 100);
   
   //calling fun 
   replacingChar(ch, 100);
   
   cout << "Your Replacing Character is: " << endl;
   cout << ch;
   
   
   
   
    return 0;
}
