#ifndef STREE_H
#define STREE_H

#include <iostream>
#include "BST.h"
#include "Student.h"

using namespace std;

class STree : public BST<Student*>
{
  public:

    STree();

    TreeNode<Student*>* search(int ID);

    bool contains(int ID);
    bool recContains(int ID, TreeNode<Student*>* curr);

    void printTree();
    void recPrint(TreeNode<Student*>* node);

};
#endif
