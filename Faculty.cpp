#include <iostream>
#include "Faculty.h"
#include "ListNode.h"

using namespace std;

Faculty::Faculty()
{
  Person();
  ID = 0;
  name = "";
  level = "";
  department = "";
  adviseeIDs = new DoublyLinkedList<int>();
}

Faculty::Faculty(int ID, string n, string l, string d)
{
  Person(ID, n, l);
  this->ID = ID;
  name = n;
  level = l;
  department = d;
  adviseeIDs = new DoublyLinkedList<int>();
}

Faculty::~Faculty()
{
  delete adviseeIDs;
}

void Faculty::addAdvisee(int a)
{
  adviseeIDs->insertBack(a);
}

ListNode<int>* Faculty::removeAdvisee(int a)
{
  return adviseeIDs->remove(a);
}

int Faculty::getID()
{
  return ID;
}

string Faculty::toString()
{
  ListNode<int>* curr = adviseeIDs->peek();
  string s = "Name: " + name + "\n"
            + "ID: " + to_string(ID) + "\n"
            + "Level: " + level + "\n"
            + "Department: " + department + "\n"
            + "Advisees: \n";
  while (curr != NULL)
  {
    s += to_string(curr->data) + "\n";
  }
  return s;
}
