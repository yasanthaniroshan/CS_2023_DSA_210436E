#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
    if(root != NULL)
    {
        cout << root->key << " ";
    }
    traverseInOrder(root->left);
    cout << root->key << " ";
    traverseInOrder(root->right);
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if(node == NULL)
    {
        new_node->key = key;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }
    else if (key < node->key)
    {
       node->left = insertNode(node->left,key);
    }
    else if(key > node->key)
    {
        node->right = insertNode(node->right,key);

    }
    return node;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
 

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