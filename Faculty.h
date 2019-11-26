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
      string department;
      DoublyLinkedList<int>* adviseeIDs;

    public:
      Faculty();
      Faculty(int ID, string n, string l, string d, DoublyLinkedList<int>* a);
      ~Faculty();

      void addAdvisee(int a);
      void removeAdvisee(int a);

};
#endif
