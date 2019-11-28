#include <iostream>
#include "Faculty.h"
#include "ListNode.h"

using namespace std;

Faculty::Faculty() // faculty constructor
{
  Person();
  ID = 0;
  name = "";
  level = "";
  department = "";
  adviseeIDs = new DoublyLinkedList<int>();
}

Faculty::Faculty(int ID, string n, string l, string d) // overloaded constructor
{
  Person(ID, n, l);
  this->ID = ID;
  name = n;
  level = l;
  department = d;
  adviseeIDs = new DoublyLinkedList<int>();
}

Faculty::~Faculty() // faculty destructor
{
  delete adviseeIDs;
}

void Faculty::addAdvisee(int a) // adds student advisee to doubly linked list
{
  adviseeIDs->insertBack(a);
}

ListNode<int>* Faculty::removeAdvisee(int a) // remove from doubly linked list
{
  return adviseeIDs->remove(a);
}

int Faculty::getID()
{
  return ID;
}

string Faculty::toString() // prints out data for a faculty object
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
