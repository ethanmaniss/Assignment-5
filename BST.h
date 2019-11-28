#ifndef BST_H
#define BST_H

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

        TreeNode<E>* search(E data);
        void insert(E data);
        TreeNode<E>* deleteNode(E data);

        TreeNode<E>* getSuccessor(TreeNode<E> *d);


        //helper functions
        bool isEmpty();
        TreeNode<E>* getMin();
        TreeNode<E>* getMax();
        TreeNode<E>* getRoot();
        void printTree();
        void recPrint(TreeNode<E> *node);
};

template <typename E>
BST<E>::BST()
{
    root = NULL; // empty tree
}

template <typename E>
BST<E>::~BST()
{
    delete root;
}

template<typename E>
TreeNode<E>* BST<E>::getRoot()
{
  return root;
}

template <typename E>
void BST<E>::recPrint(TreeNode<E> *node)
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
TreeNode<E>* BST<E>::getMax()
{
    TreeNode<E> *current = root;

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
TreeNode<E>* BST<E>::getMin()
{
    TreeNode<E> *current = root;

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
void BST<E>::insert(E data)
{
    // check if value exists in tree before proceeding
    TreeNode<E>* node = new TreeNode<E>(data);

    if(root == NULL) // empty tree
    {
        root = node;
    }
    else
    {
        // the tree is not empty, let's find the insertion point

        TreeNode<E> *current = root;
        TreeNode<E> *parent = NULL;

        while(true)
        {
            parent = current;

            if(data <= current->key)
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
TreeNode<E>* BST<E>::search(E data)
{
    if(root == NULL)
    {
        return NULL;
    }
    TreeNode<E> *current = root;
    while(current->key != data)
    {
        if(data < current->key)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
        if(current == NULL) // value is not in tree
        {
            return NULL;
        }
    }
    return current;
}

template <typename E>
TreeNode<E>* BST<E>::deleteNode(E data)
{
    if(root == NULL)
    {
        return NULL;
    }
    TreeNode<E> *parent = root;
    TreeNode<E> *current = root;
    bool isLeft = true;

    // attempt to find the node to be deleted
    while(current->key != data)
    {
        parent = current;

        if(data < current->key)
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
            return NULL;
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

        TreeNode<E> *successor = getSuccessor(current);

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
    return current;
}

template <typename E>
TreeNode<E>* BST<E>::getSuccessor(TreeNode<E> *d) //d is the node to be deleted
{
    TreeNode<E> *current = d->right;
    TreeNode<E> *sp = d; // successor's parent
    TreeNode<E> *successor = d;

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

#endif
