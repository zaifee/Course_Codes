#Tries



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










int main() {
  
  TrieNode* root = new TrieNode('-');
   
  insertWord(root, "nawaz");
  insertWord(root, "nawazish");
  insertWord(root, "hero");
  insertWord(root, "heroine");
  insertWord(root, "nozu");
  insertWord(root, "nawazishe");
  cout << " Inserted Successfully " << endl;

  string input = "h";
  string prefix = input;
 
  vector<string>ans;
  findPrefixString(root, ans,  input, prefix);
  for(auto i: ans){
    cout << i << " ";
  }
  cout << endl;





  return 0;
}

