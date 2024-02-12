#include <iostream>
#include <unordered_map>
using namespace std;
void countCharacter(string str, unordered_map<char,int>&mpp){
  for(auto it: str){
     mpp[it]++;
  }
}
int main() {
  string str = "MohdNawaz";
  unordered_map<char,int>mpp;
  countCharacter(str, mpp);

  for(auto it: mpp){
    cout << it.first << "->" << it.second<<endl;
  }
  return 0;
}
