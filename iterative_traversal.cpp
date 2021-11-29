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

 
// Iterative function to perform inorder traversal on the tree
void inorderIterative(Node* root)
{
    // create an empty stack
    stack<Node*> stack;

    // start from the root node (set current node to the root node)
    Node* curr = root;

    // if the current node is null and the stack is also empty, we are done
    while (!stack.empty() || curr != nullptr)
    {
        // if the current node exists, push it into the stack (defer it)
        // and move to its left child
        if (curr != nullptr)
        {
            stack.push(curr);
            curr = curr->left;
        }
        else {
            // otherwise, if the current node is null, pop an element from the stack,
            // print it, and finally set the current node to its right child
            curr = stack.top();
            stack.pop();
            cout << curr->data << " ";

            curr = curr->right;
        }
    }
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
