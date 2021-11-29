//Code From: https://www.techiedelight.com/inorder-tree-traversal-iterative-recursive/

#include <iostream>
#include <stack>
#include <time.h>
#define getClock() ((double)clock() / CLOCKS_PER_SEC)

using namespace std;

// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

//Code from: https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
Node* insert(Node* node, int data)
{
    /* If the tree is empty, return a new node */
    if (node == nullptr)
        return new Node(data);

    /* Otherwise, recur down the tree */
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    /* return the (unchanged) node pointer */
    return node;
}

 
// Recursive function to perform inorder traversal on the tree
void inorder(Node* root)
{
    // return if the current node is empty
    if (root == nullptr) {
        return;
    }
 
    // Traverse the left subtree
    inorder(root->left);
 
    // Display the data part of the root (or current node)
    cout << root->data << " ";
 
    // Traverse the right subtree
    inorder(root->right);
}
 
int main()
{

    Node* root = new Node(1);


   //Height = 15
    for (int x = 2; x <= 32767; x++){
        insert(root,x);
    }

    /**
    //Height = 10
    for (int x = 2; x <= 1023; x++){
        insert(root,x);
    }
    **/

    /**
    //Height = 5
    for (int x = 2; x <= 31; x++){
        insert(root,x);
    }
    **/
    double time_start = getClock();
    inorderIterative(root);
    double time_finish = getClock();

    printf("time (s)= %.6f\n", time_finish - time_start);

    return 0;
}
