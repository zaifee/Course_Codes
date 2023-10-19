


#include <iostream>
#include <vector>
using namespace std;
void findAllSubsequences(string str, string output, int index, vector<string>&ans){
    
    //base case 
    if(index >= str.length()){
        //it means ans nikal chuke hai or base case hit ho gya hai
        ans.push_back(output); //using vector 
        //without  vector 
        // cout << "->" << output << endl;
        return;
    }
    
    char ch = str[index];  //character nikal liya 
    
    //pehle include kar leta ho 
    output.push_back(ch);
    findAllSubsequences(str, output, index+1, ans);
    
    
    //ab exclude karlo -- include kar hoe character to exclude karna padega nhi string empty nhi hogi 
    output.pop_back();
    findAllSubsequences(str, output, index+1, ans);
    
    
    
    
    
    
    
    // //exclude karlo 
    
    // findAllSubsequences(str, output, index+1);
    
    
    // //include karlo -- push karo or recursion call karlo 
    // output.push_back(ch);
    // findAllSubsequences(str, output, index+1);
    
    
    
    
}

int main()
{
    string str = "abc";
    string output = " ";
    int index = 0;
    vector<string>ans;
    
 findAllSubsequences(str, output, index, ans);
 cout << "Printing All the Subsequences : " << endl;
  for(auto s: ans){
      cout << "-> " << s << endl;
  }
    
   

    return 0;
}
