#include <iostream>
#include <queue>
#include <map>
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

void createMapping(int inOrder[], int size, map<int, int>& valueToIndexMap) {
    for (int i = 0; i < size; i++) {
        int element = inOrder[i];
        int index = i;
        valueToIndexMap[element] = index;
    }
}

Node* createTreeFromInOrderAndPostOrder(map<int, int>& valueToIndexMap, int inOrder[], int postOrder[], int size, int& postOrderIndex, int inOrderStartIndex, int inOrderEndIndex) {
    // base case
    if (postOrderIndex < 0 || inOrderStartIndex > inOrderEndIndex) {
        return NULL;
    }

    // 1 case solve karlo
    int element = postOrder[postOrderIndex];
    postOrderIndex--;

    // create this element Node
    Node* root = new Node(element);

    // search karo inOrder me
    int position = valueToIndexMap[element];

    // baki case recursion sambhal lega
    root->right = createTreeFromInOrderAndPostOrder(valueToIndexMap, inOrder, postOrder, size, postOrderIndex, position + 1, inOrderEndIndex);

    root->left = createTreeFromInOrderAndPostOrder(valueToIndexMap, inOrder, postOrder, size, postOrderIndex, inOrderStartIndex, position - 1);

    return root;
}

int main() {

    int inOrder[] = {8, 14, 6, 2, 10, 4};
    int postOrder[] = {8, 6, 14, 4, 10, 2};
    int size = 6;
    int postOrderIndex = size - 1;
    int inOrderStartIndex = 0;
    int inOrderEndIndex = size - 1;
    map<int, int> valueToIndexMap;
    createMapping(inOrder, size, valueToIndexMap);

    Node* root = createTreeFromInOrderAndPostOrder(valueToIndexMap, inOrder, postOrder, size, postOrderIndex, inOrderStartIndex, inOrderEndIndex);

    cout << "printing the entire tree " << endl;
    levelOrderTraversal(root);

    return 0;
}
