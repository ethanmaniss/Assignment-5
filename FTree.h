#ifndef FTREE_H
#define FTREE_H

#include <iostream>
#include "BST.h"
#include "Faculty.h"

using namespace std;

class FTree : public BST<Faculty*>
{
  public:

    FTree();

    TreeNode<Faculty*>* search(int ID);

    bool contains(int ID);
    bool recContains(int ID, TreeNode<Faculty*>* curr);
    void printTree();
    void recPrint(TreeNode<Faculty*>* node);

};
#endif
