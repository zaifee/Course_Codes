#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
class Info{
  public:
  int maxVal;
  bool isHeap;

  Info(int a, bool b){
    this->maxVal = a;
    this->isHeap = b;
  }
};
Info checkHeap(Node* root){
 if(root == NULL){
  Info temp;
  temp.maxVal = INT_MIN;
  temp.isHeap = true;
   return temp;
 }

//  leap Node wala case 
if(root->left == NULL && root->right == NULL){
  Info temp;
  temp.maxVal = root->data; //curr data;
  temp.isHeap = true;
  return temp;
}

Info leftAns = checkHeap(root->left);
Info rightAns = checkHeap(root->right);

// 1 case mujhe solve karne do 
if(root->data > leftAns.maxVal && root->data > rightAns.maxVal && leftAns.isHeap && rightAns.isHeap){
  Info ans;
  ans.maxVal = root->data;
  ans.isHeap = true;
  return ans;
}
else{
  Info ans;
  ans.maxVal = max(root->data, max(leftAns.maxVal, rightAns.maxVal));
  ans.isHeap = false;
  return ans;

}

}
int main() {
  cout << "Hello world!" << endl;
  return 0;
}
