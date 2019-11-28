#include <iostream>
#include "Student.h"

using namespace std;

Student::Student() // student constructor
{
  Person();
  ID = 0;
  name = "";
  level = "";
  GPA = 0.0;
  major = "";
  advisor = 0;
}

Student::Student(int ID, string n, string l, double GPA, string m, int a) // overloaded constructor
{
  Person(ID, n, l);
  this->ID = ID;
  name = n;
  level = l;
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

int Student::getID()
{
  return ID;
}

int Student::getAdvisor()
{
  return advisor;
}

string Student::toString() // prints out all info for student object
{
  string s = "Name: " + name + "\n"
            + "ID: " + to_string(ID) + "\n"
            + "Level: " + level + "\n"
            + "Major: " + major + "\n"
            + "Advisor: " + to_string(advisor) + "\n";
  return s;
}
