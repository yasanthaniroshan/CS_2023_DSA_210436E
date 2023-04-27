#include <iostream>
using namespace std;

struct node
{
    int key;
    struct node *left, *right;
};

void traverseInOrder(struct node *root)
{
    if (root != NULL)
    {

        // recursing trogh left subtree untill we reach the leaf node
        traverseInOrder(root->left);

        // printing the value of the leaf node
        cout << root->key << " ";

        // recursing through right subtree untill we reach the leaf node
        traverseInOrder(root->right);
    }
}

// Function to insert a new node with given key in BST
struct node *insertNode(struct node *node, int key)
{   
    // if the node is empty then we create a new node and return it as root
    if (node == NULL)
    {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->key = key;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }

    // if the node is not empty then we check if the key is less than the node's key
    else if (key < node->key)
    {
        //recurse through the left subtree
        node->left = insertNode(node->left, key);
    }
    else if (key > node->key)
    {
        //recurse through the right subtree
        node->right = insertNode(node->right, key);
    }
    else
    {
        // if the key is equal to the node's key then we return the node
        return node;
    }
    return node;
}

// Function to delete a node with given key from BST
struct node *deleteNode(struct node *root, int key)
{   
    // if node is empty then we return the node
    if (root == NULL)
    {
        return root;
    }

    // if the key is less than the node's key then we recurse through the left subtree
    else if (key < root->key)
    {
        root->left = deleteNode(root->left, key);
    }
    // if the key is greater than the node's key then we recurse through the right subtree
    else if (key > root->key)
    {
        root->right = deleteNode(root->right, key);
    }
    // if the key is equal to the node's key then we delete the node after checking whether how many children the node has
    else
    {
        // if the node has no children then we delete the node
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        // if the node has only one child in right then we delete the node and replace it with its child
        else if (root->left == NULL)
        {
            struct node *new_node = root;
            root = root->right;
            free(new_node);
        }
        // if the node has only one child in left then we delete the node and replace it with its child
        else if (root->right == NULL)
        {
            struct node *new_node = root;
            root = root->left;
            free(new_node);
        }
        // if the node has two children then we find the minimum in the right subtree and replace it with the node key and delete the minimum node
        else
        {
            struct node *new_node = root->right;
            while (new_node->left != NULL)
            {
                new_node = new_node->left;
            }
            root->key = new_node->key;
            root->right = deleteNode(root->right, new_node->key);
        }
    }
    return root;
}

// Driver code
int main()
{
    struct node *root = NULL;

    int operation;
    int operand;
    cin >> operation;

    while (operation != -1)
    {
        switch (operation)
        {
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