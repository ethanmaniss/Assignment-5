#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "Person.h"

using namespace std;

// student is a derived class
class Student : public Person
{
    private:
      int ID;
      string name;
      string level;
      double GPA;
      string major;
      int advisor;

    public:
      Student();
      Student(int ID, string n, string l, double GPA, string m, int a);
      ~Student();

      void setAdvisor(int a);
      int getID();
      int getAdvisor();
      string toString();

};
#endif
