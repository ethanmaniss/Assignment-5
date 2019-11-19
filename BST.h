#include <iostream>
#include "TreeNode.h"

using namespace std;

template <typename E> // allows BST to hold any type of data
class BST
{
    private:
        TreeNode<E> *root;

    public:
        BST();
        ~BST();

        bool search(int value);
        void insert(int value);
        bool deleteNode(int value);

        TreeNode* getSuccessor(TreeNode *d);


        //helper functions
        bool isEmpty();
        TreeNode<E>* getMin();
        TreeNode<E>* getMax();
        void printTree();
        void recPrint(TreeNode *node);
};

template <typename E>
BST<E>::BST()
{
    root = NULL; // empty tree
}

template <typename E>
BST<E>::~BST()
{
    // research this (character building)
}

template <typename E>
void BST<E>::recPrint(TreeNode *node)
{
    if(node == NULL)
    {
        return;
    }
    recPrint(node->left);
    cout << node->key << endl;
    recPrint(node->right);
}

template <typename E>
void BST<E>::printTree()
{
    recPrint(root);
}

template <typename E>
TreeNode* BST<E>::getMax()
{
    TreeNode *current = root;

    if(root == NULL)
    {
        return NULL;
    }

    while(current->right != NULL)
    {
        current = current->right; // keep going down the right side of tree
    }

    return current; // or return &(current->key)
}

template <typename E>
TreeNode* BST<E>::getMin()
{
    TreeNode *current = root;

    if(root == NULL)
    {
        return NULL;
    }

    while(current->left != NULL)
    {
        current = current->left; // keep going down the left side of tree
    }

    return current; // or return &(current->key)
}

template <typename E>
void BST<E>::insert(int value)
{
    // check if value exists in tree before proceeding
    TreeNode node = TreeNode(value);

    if(root == NULL) // empty tree
    {
        root = node;
    }
    else
    {
        // the tree is not empty, let's find the insertion point

        TreeNode *current = root;
        TreeNode *parent = NULL;

        while(true)
        {
            parent = current;

            if(value < current->key)
            {
                // we go left
                current = current->left;

                if(current == NULL)
                {
                    parent->left = node;
                    break;
                }
            }
            else
            {
                // we go right
                current = current->right;

                if(current == NULL)
                {
                    parent->right = node;
                    break;
                }
            }
        }
    }
}

template <typename E>
bool BST<E>::search(int value) // for assignment 5 will have to return something else
{
    if(root == NULL)
    {
        return false;
    }
    // we make it this far, we know the tree is not empty
    // lets attempt to find the key
    TreeNode *current = root;
    while(current->key != value)
    {
        if(value < current->key)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
        if(current == NULL) // value is not in tree
        {
            return false;
        }
    }
    return true;
}

template <typename E>
bool BST<E>::deleteNode(int value)
{
    if(root == NULL)
    {
        return false;
    }
    TreeNode *parent = root;
    TreeNode *current = root;
    bool isLeft = true;

    // attempt to find the node to be deleted
    while(current->key != value)
    {
        parent = current;

        if(value < current->key)
        {
            // go left
            isLeft = true;
            current = current->left;
        }
        else
        {
            // we go right
            isLeft = false;
            current = current->right;
        }

        if(current == NULL) // value doesn't exist
        {
            return false;
        }
    }
    // if we make it here, we found the node to be deleted

    if(current->left == NULL && current->right == NULL) // node is a leaf, no children
    {
        if(current == root)
        {
            root = NULL;
        }
        else if(isLeft)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }
    }
    else if(current->right == NULL) // node to be deleted has one child, it's a left (no right child)
    {
        if(current == root)
        {
            root = current->left;
        }
        else if(isLeft)
        {
            parent->left = current->left;
        }
        else
        {
            parent->right = current->left;
        }
    }
    else if(current->left == NULL) // node to be deleted has one child, it's a right (no left child)
    {
        if(current == root)
        {
            root = current->right;
        }
        else if(isLeft)
        {
            parent->left = current->right;
        }
        else
        {
            parent->right = current->right;
        }
    }
    else
    {
        // the node to be deleted has two children.
        // oh shit bro

        TreeNode *successor = getSuccessor(current);

        if(current == root)
        {
            root = successor;
        }
        else if(isLeft)
        {
            parent->left = successor;
        }
        else
        {
            parent->right = successor;
        }
        successor->left = current->left;
    }
    return true;
}

template <typename E>
TreeNode* BST<E>::getSuccessor(TreeNode *d) //d is the node to be deleted
{
    TreeNode *current = d->right;
    TreeNode *sp = d; // successor's parent
    TreeNode *successor = d;

    while(current != NULL)
    {
        sp = successor;
        successor = current;
        current = current->left;
    }
    // we made it here, that means we found the successor
    if(successor != d->right)
    {
        sp->left = successor->right;
        successor->right = d->right;
    }
    return successor;
}
