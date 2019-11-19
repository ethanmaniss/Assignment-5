#include <iostream>
#include <string>
#include "DoublyLinkedList.h"

using namespace std;

// base class for student and faculty classes
class Person
{
    private:

    public:
        int ID;
        string name;
        string level;
};

// student is a derived class
class Student: public Person
{
    private:

    public:
        string major;
        double GPA;
        int advisor;
};

// faculty is a derived class
class Faculty: public Person
{
    private:

    public:
        string department;
        DoublyLinkedList<int> adviseeIds;

};
