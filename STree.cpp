#include <iostream>
#include "STree.h"

using namespace std;

STree::STree()
{
  BST<Student*>();
}


TreeNode<Student*>* STree::search(int ID)
{
  if(BST::getRoot() == NULL)
  {
      return NULL;
  }
  TreeNode<Student*> *current = BST::getRoot();
  while(current->key->getID() != ID)
  {
      if(ID < current->key->getID())
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

bool STree::contains(int ID)
{
  return recContains(ID, BST::getRoot());
}

bool STree::recContains(int ID, TreeNode<Student*>* curr)
{
  if (curr == NULL) // node is leaf
    return false;

  else if (curr->key->getID() == ID) // node contains ID
    return true;

  return recContains(ID, curr->left) || recContains(ID, curr->right);
}

void STree::printTree()
{
  if (BST::getRoot() == NULL)
  {
    cout << "Error: Tree is empty" << endl;
  }
  recPrint(BST::getRoot());
}

void STree::recPrint(TreeNode<Student*>* node)
{
  if(node == NULL)
  {
      return;
  }
  recPrint(node->left);
  cout << node->key->toString() << endl;
  recPrint(node->right);
}
