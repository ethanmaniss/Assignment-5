#include <iostream>
#include "Student.h"

using namespace std;

Student::Student()
{
  Person();
  GPA = 0.0;
  major = "";
  advisor = 0;
}

Student::Student(int ID, string n, string l, double GPA, string m, int a)
{
  Person(ID, n, l);
  this->GPA = GPA;
  major = m;
  advisor = a;
}

Student::~Student()
{

}

void Student::setAdvisor(int a)
{
  advisor = a;
}

string Student::toString()
{
  string s = Person::toString() +
            + "Major: " + major + "\n"
            + "Advisor: " + advisor + "\n";
  return s;
}
