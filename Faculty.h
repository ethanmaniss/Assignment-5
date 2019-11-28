#ifndef FACULTY_H
#define FACULTY_H
#include <iostream>
#include "DoublyLinkedList.h"
#include "Person.h"

using namespace std;

// faculty is a derived class
class Faculty : public Person
{
    private:
      int ID;
      string name;
      string level;
      string department;
      DoublyLinkedList<int>* adviseeIDs;

    public:
      Faculty();
      Faculty(int ID, string n, string l, string d);
      ~Faculty();

      void addAdvisee(int a);
      ListNode<int>* removeAdvisee(int a);
      int getID();
      string toString();

};
#endif
