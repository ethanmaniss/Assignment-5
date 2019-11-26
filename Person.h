#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>

using namespace std;

// base class for student and faculty classes
class Person
{
    private:
      int ID;
      string name;
      string level;

    public:
      Person(); // default constructor
      Person(int ID, string n, string l);
      ~Person();
};
#endif
