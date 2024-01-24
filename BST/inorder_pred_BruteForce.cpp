/* This is the Node class definition

class Node {
public:
    Node* left;
    Node* right;
    int data;

    Node(int data) {
        this->left = NULL;
        this->right = NULL;
        this->data = data;
    }
};
*/
 void inorder(Node* root, vector<int>&in){
	 if(root == NULL) return;
	 
	 inorder(root->left, in);
	 in.push_back(root->data);
	 inorder(root->right, in);
 }
Node* findPredecessor(Node* root, Node* p) {
    vector<int>in;
	inorder(root, in);
	Node* pred = nullptr;
	for(int i=0; i<in.size(); i++){
		if(in[i] == p->data){
			if(i > 0){
				pred = new Node(in[i-1]);
			}
			break;
		}
	}
	return pred;
	
	
	
}
