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
        children = NULL;
    }
    
    this->isTerminal = false;
}
    
    
    
};


bool searchWord(TrieNode* root, string word){
 
 if(word.length() == 0){
     return root->isTerminal; //it return terminal value 
 }   
 
 char ch = word[0];
 int index = ch - 'a';
 TrieNode* child;
 
 if(root->children[index] != NULL){
     //present or not 
     child = root->children[index];
 }
 else{
     //not present 
     return false;
 }
 //ek character ke liye solve kar liya hai 
 bool recurAns = searchWord(child, substr(1));
 return recurAns;
 
}



//insert at node 
void insertWord(TrieNode* root, string word){
    // cout << 
    if(word.length() == 0){
        root->isTerminal = true;
        return;
    }
    
    //Present or absent 
    char ch = word[0]; //value 
    int index = ch - 'a';
    TreeNode* child;
    
    if(root->children != NULL){
        //present 
        child = root->children[index];
    }
    else{
        //make a new Node and then traverse it 
        child = new TrieNode(ch);
        root->children[index] = child;
        
    }
    
    //recursion 
    insertWord(child, word.substr(1));
    
}


void deleteWord(TrieNode* root, string word){
    if(word.length() == 0){
        return->isTerminal = false; //node mil gyi false mark kar do
    }
    
    // 1 case mera 
    char ch = word[0];
    int index = ch-'a';
    TrieNode* chid;
    
    if(root->children[index] != NULL){
        
        //present 
        child = root->children[index];
    }
    else{
        //not present 
        return;
    }
    return false;
}





int main()
{
    TrieNode* root = new TrieNode('-');
    
    insertWord(root, "CATER");
    insertWord(root, "CARE");
    insertWord(root, "CoM");
       insertWord(root, "LOVER");
        insertWord(root, "LOVED");
        insertWord(root, "LOAD");
         insertWord(root, "BAT");
          insertWord(root, "CAR");
          insertWord(root, "CAT");
          insertWord(root, "LOV");
          
          cout << "Insertion done " << endl;
          
          if(searchWord("CoM")){
              cout << "Found " << endl;
          }
          else{
              cout << "Not found " << endl;
          }

    return 0;
}
