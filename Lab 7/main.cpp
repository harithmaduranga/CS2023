#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
    if(root!=NULL){
        traverseInOrder(root->left);     // Traverse left side first
        cout << root->key << " ";        // Then output self
        traverseInOrder(root->right);    // Then right side
    }
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
    // This is the base case.
    // If self is NULL, we can insert here.
    if(node==NULL){
        struct node* newNode = (struct node*)malloc(sizeof(struct node));  // Create new node in the memory to store value
        newNode->key = key;   // Store value
        newNode->left = NULL; // children are null
        newNode->right = NULL;
        node = newNode;
    }else{
        // Find where to insert comparing the keys.
        if(key < node->key){
            node->left = insertNode(node->left,key);
        }else{
            node->right = insertNode(node->right,key);
        }
    }
    return node; // Return inserted input node.
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if(root==NULL){
        return root;   // Nothing to delete.
    }
    else{
        if(key < root->key){
            root->left = deleteNode(root->left,key);  // Delete from left side if less than current key
        }else if(key > root->key){
            root->right = deleteNode(root->right,key); // Delete from left side if greater than current key
        }else{
            // If deleting node has no children
            if(root->left == NULL && root->right == NULL){
                return NULL;
            }
            // If deleting node has only right child, take the right child, delete the node, insert right child at the place of the node.
            else if(root->left == NULL){
                struct node* newRoot = root->right;
                free(root);
                return newRoot;
            // If deleting node has only left child, take the left child, delete the node, insert left child at the place of the node.
            }else if(root->right == NULL){
                struct node* newRoot = root->left;
                free(root);
                return newRoot;
            }
            // If the deleting node has both children, take the minimum value of its right node.
            // It is greater than all elements of the left node and less than all rest elements of the right node.
            // Update the root key with that right minimum value.
            else{
                struct node* newRoot = root->right;
                while(newRoot->left != NULL){
                    newRoot = newRoot->left;
                }
                root->key = newRoot->key;
                root->right = deleteNode(root->right, newRoot->key); // Delete that minimum right value from its original place.
            }
        }
    }
    return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }

  traverseInOrder(root);
}
