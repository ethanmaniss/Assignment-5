#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>

template <typename E>
class TreeNode
{
    public:
        TreeNode();
        TreeNode(E k); // k = key, in this example is also the value(data)
        ~TreeNode(); // when creating a template class destructor must be virtual

        E key;
        TreeNode<E> *left;
        TreeNode<E> *right;
};

#endif

template <typename E>
TreeNode<E>::TreeNode()
{
    left = NULL;
    right = NULL;
}

template <typename E>
TreeNode<E>::TreeNode(E k)
{
    key = k;
    left = NULL;
    right = NULL;
}

template <typename E>
TreeNode<E>::~TreeNode()
{
    left = NULL;
    right = NULL;
    delete key;
}
