#include <iostream>
#include "Person.h"

using namespace std;

Person::Person()
{
  ID = 0;
  name = "";
  level = "";
}

Person::Person(int ID, string n, string l)
{
  this->ID = ID;
  name = n;
  level = l;
}

Person::~Person()
{

}

int Person::getID()
{
  return ID;
}

string Person::toString()
{
  string s = "Name: " + name + "\n"
            + "ID: " + to_string(ID) + "\n"
            + "Level: " + level + "\n";
  return s;
}

bool Person::operator==(const Person& x) // compares if two ids are equivalent
{
  return (this->getID() == x.ID);
}

bool Person::operator<=(const Person& x) // returns boolean true if object has a lesser id than the parameter object
{
  return (this->getID() <= x.ID);
}

bool Person::operator>=(const Person& x)
{
  return (this->getID() >= x.ID);
}
