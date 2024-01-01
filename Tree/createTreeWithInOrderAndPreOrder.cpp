
#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* createTree() {
    cout << "Enter any value for the Node : " << endl;
    int data;
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    // root create karlo
    Node* root = new Node(data);

    // left subtree create karlo
    root->left = createTree();

    // right subtree
    root->right = createTree();

    return root;
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while (q.size() > 1) {
        Node* front = q.front(); // front ek Node hai galti ki int front likha rha tha
        q.pop();

        if (front == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            // Valid Node wala case

            cout << front->data << " ";

            if (front->left != NULL) {
                q.push(front->left);
            }
            if (front->right != NULL) {
                q.push(front->right);
            }
        }
    }
}

int searchInOrder(int inOrder[], int size, int targetElement) {
    for (int i = 0; i < size; i++) {
        if (inOrder[i] == targetElement) {
            return i;
        }
    }
    return -1;
}

Node* constructTreeFromPreOrderAndInOrderTraversal(int preOrder[], int inOrder[], int size, int& preOrderIndex, int inOrderStartingIndex, int inOrderEndingIndex) {
    // outofbound Condition
    if (preOrderIndex >= size || inOrderStartingIndex > inOrderEndingIndex) {
        return NULL;
    }

    // 1 element nikal lo preOrder me se
    int element = preOrder[preOrderIndex];
    preOrderIndex++;

    // ab is element ke liye node create karlo
    Node* root = new Node(element);

    // Now search this element in InOrder
    int position = searchInOrder(inOrder, size, element);

    // baaki element laga do left me or right me bcz hmme jaha element lagane hai waha ki position mil gyi -- change in position
    root->left = constructTreeFromPreOrderAndInOrderTraversal(preOrder, inOrder, size, preOrderIndex, inOrderStartingIndex, position - 1);

    // dusra root ke right me laga lo
    root->right = constructTreeFromPreOrderAndInOrderTraversal(preOrder, inOrder, size, preOrderIndex, position + 1, inOrderEndingIndex);

    return root;
}

int main() {
    int preOrder[] = {2, 8, 10, 6, 4, 12};
    int inOrder[] = {10, 8, 6, 2, 4, 12}; // Corrected inOrder array
    int size = 6;
    int preOrderIndex = 0;
    int inOrderStartingIndex = 0;
    int inOrderEndingIndex = 5;
    Node* root = constructTreeFromPreOrderAndInOrderTraversal(preOrder, inOrder, size, preOrderIndex, inOrderStartingIndex, inOrderEndingIndex);
    cout << "Printing the Entire root " << endl;
    levelOrderTraversal(root);

    return 0;
}


//Using Map : 

#include <iostream>
#include<map>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* createTree() {
    cout << "Enter any value for the Node : " << endl;
    int data;
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    // root create karlo
    Node* root = new Node(data);

    // left subtree create karlo
    root->left = createTree();

    // right subtree
    root->right = createTree();

    return root;
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while (q.size() > 1) {
        Node* front = q.front(); // front ek Node hai galti ki int front likha rha tha
        q.pop();

        if (front == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            // Valid Node wala case

            cout << front->data << " ";

            if (front->left != NULL) {
                q.push(front->left);
            }
            if (front->right != NULL) {
                q.push(front->right);
            }
        }
    }
}
// map is passed by reference because we want to track the value
void createMapping(int inOrder[], int size , map<int,int>& valueToIndexMapped){
 for(int i=0; i<size; i++){
   int element = inOrder[i];
   int index = i;
   valueToIndexMapped[element] = index; //pushing value with their index
 }
}
int searchInOrder(int inOrder[], int size, int targetElement) {
    for (int i = 0; i < size; i++) {
        if (inOrder[i] == targetElement) {
            return i;
        }
    }
    return -1;
}

Node* constructTreeFromPreOrderAndInOrderTraversal(map<int,int>& valueToIndexMapped,int preOrder[], int inOrder[], int size, int& preOrderIndex, int inOrderStartingIndex, int inOrderEndingIndex) {
    // outofbound Condition
    if (preOrderIndex >= size || inOrderStartingIndex > inOrderEndingIndex) {
        return NULL;
    }

    // 1 element nikal lo preOrder me se
    int element = preOrder[preOrderIndex];
    preOrderIndex++;

    // ab is element ke liye node create karlo
    Node* root = new Node(element);

    // Now search this element in InOrder
    int position = searchInOrder(inOrder, size, element); 

    // baaki element laga do left me or right me bcz hmme jaha element lagane hai waha ki position mil gyi -- change in position
    root->left = constructTreeFromPreOrderAndInOrderTraversal(valueToIndexMapped,preOrder, inOrder, size, preOrderIndex, inOrderStartingIndex, position - 1);

    // dusra root ke right me laga lo
    root->right = constructTreeFromPreOrderAndInOrderTraversal(valueToIndexMapped,preOrder, inOrder, size, preOrderIndex, position + 1, inOrderEndingIndex);

    return root;
}

int main() {
    int preOrder[] = {2, 8, 10, 6, 4, 12};
    int inOrder[] = {10, 8, 6, 2, 4, 12}; // Corrected inOrder array
    int size = 6;
    int preOrderIndex = 0;
    int inOrderStartingIndex = 0;
    int inOrderEndingIndex = 5;
    map<int,int>valueToIndexMapped;
    createMapping(inOrder, size, valueToIndexMapped);
    Node* root = constructTreeFromPreOrderAndInOrderTraversal(valueToIndexMapped,preOrder, inOrder, size, preOrderIndex, inOrderStartingIndex, inOrderEndingIndex);
    cout << "Printing the Entire root " << endl;
    levelOrderTraversal(root);

    return 0;
}
