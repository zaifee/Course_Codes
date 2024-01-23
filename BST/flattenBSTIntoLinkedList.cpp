// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Node of the binary tree
struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

// Function to print flattened
// binary Tree
void print(Node* parent)
{
	Node* curr = parent;
	while (curr != NULL)
		cout << curr->data << " " ,curr = curr->right;
}

// Function to perform in-order traversal
// recursively
void inorder(Node* root, Node* &prev)
{
	// Base Case
  if(!root)return;
  inorder(root->left, prev);
  prev->left = 0;
  prev->right = root;
  prev = root;
  inorder(root->right, prev);
}

  


Node* flatten(Node* root){
    Node* dummy = new Node(-1);
    Node* prev = dummy;
    inorder(root, prev); //prev save the predeceessor taki me uske right me current Node ko set kar pao 
    prev->left = prev->right = 0; //last wali Node ko null point kar rahe 
    
    root = dummy->right;
    return root;
    
    
}
int main()
{

      Node* root = new Node(5);
      root->left = new Node(3);
      root->right = new Node(7);
      root->left->left = new Node(2);
      root->left->right = new Node(4);
      root->right->left = new Node(6);
      root->right->right = new Node(8); //yaha galti ki ti
      
      
      
      
      
      
      
	// Calling required function
	print(flatten(root));

	return 0;
}
