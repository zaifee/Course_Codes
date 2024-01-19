 #include <iostream>
#include <queue>
using namespace std;
class Node{
 public:
int data;
int childrenCount;
Node** childrens;

Node(int data){
this->data = data;
this->childrenCount = 0;
this->childrens = 0;
}
};

Node* takeInput(){
  int data, count;
  cout << "Enter the root data " << endl;
  cin >> data;
  cout << "Enter the children count for data: " << data << "node" << endl;
  cin >> count;
  // create the roor 
  Node* root = new Node(data); //array to store links of children
  root->childrenCount = count;
  root->childrens = new Node*[count];
  for(int i=0; i<count; i++){
    root->childrens[i] = takeInput();
  }
  return root;
  
}
void printLevelOrder(Node* root){
  queue<Node*>q;
  q.push(root);
  q.push(NULL);
  while(!q.empty()){
    auto front = q.front();
    q.pop();

    if(front == NULL){
      cout << endl;
      if(!q.empty()){
        q.push(NULL);
      }
    }
    else{
      cout << front->data << " ";
      for(int i=0; i<front->childrenCount; i++){
        //front ka chld null na ho to push kardo 
         if(front->childrens[i]){
           q.push(front->childrens[i]);
         }
      }
    }
  }
}





int main(){
Node* root = takeInput();
printLevelOrder(root);
  
  return 0;
}
