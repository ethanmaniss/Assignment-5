#include <iostream>
#include "FTree.h"

using namespace std;

FTree::FTree()
{
  BST<Faculty*>();
}


TreeNode<Faculty*>* FTree::search(int ID)
{
  if(BST::getRoot() == NULL)
  {
      return NULL;
  }
  TreeNode<Faculty*> *current = BST::getRoot();
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

bool FTree::contains(int ID)
{
  TreeNode<Faculty*>* curr = BST::getRoot();
  return recContains(ID, curr);
}

bool FTree::recContains(int ID, TreeNode<Faculty*>* curr)
{
  if (curr == NULL) // node is leaf
    return false;

  else if (curr->key->getID() == ID) // node contains ID
    return true;

  return recContains(ID, curr->left) || recContains(ID, curr->right);
}

void FTree::printTree()
{
  if (BST::getRoot() == NULL)
  {
    cout << "Error: Tree is empty" << endl;
  }
  recPrint(BST::getRoot());
}

void FTree::recPrint(TreeNode<Faculty*>* node)
{
  if(node == NULL)
  {
      return;
  }
  recPrint(node->left);
  cout << node->key->toString() << endl;
  recPrint(node->right);
}
