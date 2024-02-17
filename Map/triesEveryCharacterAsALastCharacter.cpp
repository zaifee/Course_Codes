// #Tries



#include <iostream>
#include <vector>
using namespace std;
class TrieNode{
public:
char val;
TrieNode* children[26];
bool isTerminal;

TrieNode(char value){
  this->val = value;
  for(int i=0; i<26; i++){
     children[i] = NULL;
  }
 this->isTerminal = false;

}


};

void insertWord(TrieNode* root, string word){

  //base case 
  if(word.length() == 0){
    root->isTerminal = true; //yaha galti ki thi
    return;
  }

  //find out the value 
  char value = word[0];
  int index = value-'a';
  TrieNode* child;


  if(root->children[index] != NULL){
    //present hai 
    child = root->children[index];

  }
  else{
     child = new TrieNode(value);
     root->children[index] = child;
     
  }

  //baki case recursion dekh lega 
  insertWord(child, word.substr(1));
}
void storeString(TrieNode* root, vector<string>& ans, string& input, string& prefix){
  //base case 
  if(root->isTerminal == true){
    ans.push_back( prefix + input);

    //ne need of return;

  }

  //char a to z dekhlo hai kya niche 
  for(char ch = 'a';  ch <= 'z'; ch++){
   int index = ch-'a';
   TrieNode* next = root->children[index];

   if(next != NULL){
      input.push_back(ch);

      //baki rec se 
      storeString(next, ans, input, prefix);

      //backtrack 
      input.pop_back();
   }

  }
}


void findPrefixString(TrieNode* root, vector<string>&ans,  string input, string& prefix){
  //base case 
  if(input.length() == 0){
    TrieNode* lastChar = root;
    storeString(lastChar, ans, input, prefix);
    return;
  }

  char ch = input[0];
  int index = ch-'a';
  TrieNode* child;

  if(root->children[index] != NULL){
    //char present hai 
    child = root->children[index];

  }
  else{
    return;
  }

  //recusive call 
  findPrefixString(child, ans,  input.substr(1), prefix);





}

//we are taking vector of vector because we are using assuming every character as a last character and we are trying to find all the possible ans for that 
vector<vector<string>> getSuggestion(TrieNode* root, string input){
 
 vector<vector<string>> output;
 string inputHelper = ""; //saving curr character in inputHelper
 TrieNode* prev = root; //making copy so that root node will not be impact in future

 for(int i=0; i<input.length(); ++i){
    char lastChar = input[i];
    int index = lastChar-'a';
    TrieNode* curr = prev->children[index];

     
     if(curr == NULL){
      //it means aesa koi child exist nhi karta 
      break;
     }
     else{
        vector<string>nicheKaAns;
        inputHelper.push_back(lastChar);
        string dummy = "";
        storeString(curr, nicheKaAns, inputHelper, dummy);
        output.push_back(nicheKaAns);
        //ye important bhul jate hai line 136 ko 
        prev = curr;

     }

 }

 return output;

}







int main() {
  
  TrieNode* root = new TrieNode('-');
   
  insertWord(root, "nawaz");
  insertWord(root, "nawazish");
  insertWord(root, "hero");
  insertWord(root, "heroine");
  insertWord(root, "nozu");
  insertWord(root, "nawazishe");
  cout << " Inserted Successfully " << endl;
   
   auto ans = getSuggestion(root, "na");
  // Printing ans 
  for(int i=0; i<ans.size(); ++i){
    cout << i << "->";
    for(auto str: ans[i]){
      cout << str << " ";
    } cout << endl; 
  }






  // string input = "h";
  // string prefix = input;
 
  // vector<string>ans;
  // findPrefixString(root, ans,  input, prefix);
  // for(auto i: ans){
  //   cout << i << " ";
  // }
  // cout << endl;





  return 0;
}
