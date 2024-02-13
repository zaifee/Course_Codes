#include <iostream>
using namespace std;
class TrieNode{
public:
char value;
TrieNode* children[26];
bool isTerminal;

TrieNode(char val){
this->value = val;
for(int i=0; i<26; i++){
  children[i] = NULL;
}
this->isTerminal = false;

}



};
void insertWordInTrie(TrieNode* root, string word){
  // cout << "Recevied word " << word << "for insertion " << endl;
  if(word.length() == 0){
    root->isTerminal = true; //with isTerminal we are marking end of the string 
    return;
  }

  char value = word[0];
  int index = value -'a';
  TrieNode* child;

  if(root->children[index] != NULL){
    //if present 
    child = root->children[index];
  }
  else{
    //not preset 
    child = new TrieNode(value);
    root->children[index] = child;
  }

  //baki case recursion dekh lega 
  insertWordInTrie(child,  word.substr(1));
  

}

bool searchNodeInTrie(TrieNode* root, string word){

  if(word.length() == 0){
    return root->isTerminal; //terminal Node pe the it will return true else return false;
  }

  char ch = word[0];
  int index = ch-'a';
  TrieNode* child;

  if(root->children[index] != NULL){
    //present of found 
    child = root->children[index];
  }
  else{
    //not found 
    return false;
  }
  bool recursiveAns = searchNodeInTrie(child, word.substr(1));
  return recursiveAns;
}

void deleteWordFromTrie(TrieNode* root, string word){
  if(word.length() == 0){
    root->isTerminal = false;
     return;
  }

  char value = word[0];
  int index = value-'a';
  TrieNode* child;

  if(root->children[index] != 0){
    //present hai traverse karte jao 
    child = root->children[index];

  }else{
    //Not found
    return;
  }

  //ek case solve ho gya baki recusion ko dedo 
  deleteWordFromTrie(child, word.substr(1)); //substr remove the first character and starts from the second character



}







int main() {
  TrieNode* root = new TrieNode('-');
  insertWordInTrie(root , "nawaz");
  insertWordInTrie(root, "nawazish");
  insertWordInTrie(root, "helloji");
  cout << "Inserted Successfully " << endl;
  
  if(searchNodeInTrie(root,"nawaz")){
    cout << "Found" << endl;
  }
  else{
    cout << "Not Found" << endl;
  }
   deleteWordFromTrie(root, "nawaz");
if(searchNodeInTrie(root,"nawaz")){
    cout << "Found" << endl;
  }
  else{
    cout << "Not Found" << endl;
  }


  return 0;
}
