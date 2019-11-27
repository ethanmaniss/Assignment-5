#include <iostream>
#include "Faculty.h"

using namespace std;

Faculty::Faculty()
{
  Person();
  department = "";
  adviseeIDs = new DoublyLinkedList<int>();
}

Faculty::Faculty(int ID, string n, string l, string d, DoublyLinkedList<int>* a)
{
  Person(ID, n, l);
  department = d;
  adviseeIDs = a;
}

Faculty::~Faculty()
{
  delete adviseeIDs;
}

void Faculty::addAdvisee(int a)
{
  adviseeIDs->insertBack(a);
}

void Faculty::removeAdvisee(int a)
{
  adviseeIDs->remove(a);
}

string Faculty::toString()
{
  string s = Person::toString() +
            + "Department: " + department + "\n";
  return s;
}
